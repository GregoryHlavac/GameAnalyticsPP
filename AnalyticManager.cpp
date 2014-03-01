#include "stdafx.h"
#include "AnalyticManager.h"

#include <algorithm>

#include "MD5.h"
#include "sha1.h"

#include "SubmissionHandler.h"

#include "Event.pb.h"

#include "Event.h"
#include "UserEvent.h"
#include "ErrorEvent.h"
#include "DesignEvent.h"
#include "BusinessEvent.h"

#include <jansson.h>
#include <ProtoJSON.h>

using namespace boost::network;
using namespace boost::network::http;

namespace GameAnalytics
{
#pragma region Generate UID & SID

#ifdef WIN32
#include <iptypes.h>
#include <iphlpapi.h>
#include <objbase.h>
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "rpcrt4.lib")

	std::string AnalyticManager::generateUserIdentifier()
	{
		std::string retVal;

		IP_ADAPTER_INFO info[16];

		// Get info for all the network adapters.
		DWORD dwBufLen = sizeof(info);
		DWORD dwStatus = GetAdaptersInfo(info, &dwBufLen);
		if (dwStatus != ERROR_SUCCESS)
		{
			// ---------------------- //
			// ------INCOMPLETE------ //
			// ---------------------- //
			/* deal with error */
		}
		else
		{
			PIP_ADAPTER_INFO pAdapterInfo = info;

			// Iterate through the adapter array until we find one.
			// (Will most likely be the first.)
			while (pAdapterInfo && pAdapterInfo == 0)
			{
				pAdapterInfo = pAdapterInfo->Next;
			}

			if (!pAdapterInfo)
			{
				// No network adapter found. In my code I just use a GUID at this point,
				//   (same code to get a session ID), but I'll leave that up to you.
			}
			else
			{
				// Get a hash of the MAC address using SHA1.
				unsigned char hash[20];
				char hexstring[41];
				sha1::calc(pAdapterInfo->Address, pAdapterInfo->AddressLength, hash);
				sha1::toHexString(hash, hexstring);
				retVal = hexstring;

				// Remove any hyphens.
				retVal.erase(std::remove(retVal.begin(), retVal.end(), '-'), retVal.end());
			}
		}

		return retVal;
	}

	std::string AnalyticManager::generateSessionIdentifier()
	{
		std::string retVal;

		// Get the GUID.
		GUID guid;
		CoCreateGuid(&guid);

		// Turn the GUID into an ASCII string.
		RPC_CSTR str;
		UuidToStringA((UUID*)&guid, &str);

		// Get a standard string out of that.
		retVal = (LPSTR)str;

		// Remove any hyphens.
		retVal.erase(std::remove(retVal.begin(), retVal.end(), '-'), retVal.end());

		return retVal;
	}
#endif

#pragma endregion

	void AnalyticManager::Initialize(std::string secretKey, std::string gameKey, std::string apiKey, std::string buildIdentifier, std::string userID /*= generateUserIdentifier()*/, std::string sessionID /*= generateSessionIdentifier()*/)
	{
		mSecretKey = secretKey;
		mGameKey = gameKey;
		mAPIKey = apiKey;
		mBuildIdentifier = buildIdentifier;
		mUID = userID;
		mSID = sessionID;

		mInitialized = true;

		mClient = std::shared_ptr<boost::network::http::client>(new boost::network::http::client());

		mUserLock = SPMutex(new std::mutex());
		mBusinessLock = SPMutex(new std::mutex());
		mDesignLock = SPMutex(new std::mutex());
		mErrorLock = SPMutex(new std::mutex());

		mSubmitUE = std::thread(&AnalyticManager::sendUserEvents);
		mSubmitUE.detach();

		mSubmitBE = std::thread(&AnalyticManager::sendBusinessEvents);
		mSubmitBE.detach();

		mSubmitDE = std::thread(&AnalyticManager::sendDesignEvents);
		mSubmitDE.detach();

		mSubmitEE = std::thread(&AnalyticManager::sendErrorEvents);
		mSubmitEE.detach();
	}

#pragma region Event Sending
	void AnalyticManager::Send(Event* evt)
	{
		std::string rawJSON = evt->constructJSON(mUID, mSID, mBuildIdentifier);
		std::string authHeaderData = md5(rawJSON + mSecretKey);

		http::client::request req(getURL(evt->getCategory()));

 		req << header("Authorization", authHeaderData);
 		req << header("Content-Type", CONTENT_TYPE);
		req << header("Content-Length", std::to_string(rawJSON.length()));
 		req << body(rawJSON);

		http::client::response resp = mClient->post(req);

		uint16_t r = status(resp);
	}

#pragma region Batch
	void AnalyticManager::sendUserEvents()
	{
		for (;;)
		{
			std::this_thread::sleep_for(std::chrono::seconds(SUBMIT_INTERVAL_SECONDS));

			if (mUserEvents.size() > 0 && mUserLock->try_lock())
			{
				std::vector<ProtocolBuffers::GameAnalytics::Event> messages;
				for (auto evt : mUserEvents)
				{
					evt->setParameters(mUID, mSID, mBuildIdentifier);
					messages.push_back(*evt->getMessage());
				}

				std::string rawJSON = ProtoJSON::asJSON(messages, ProtoJSON::FormatCompact, true);
				std::string authHeaderData = md5(rawJSON + mSecretKey);

				http::client::request req(getURL("user"));

				req << header("Authorization", authHeaderData);
				req << header("Content-Type", CONTENT_TYPE);
				req << header("Content-Length", std::to_string(rawJSON.length()));
				req << body(rawJSON);

				http::client::response resp = mClient->post(req);

				uint16_t r = status(resp);

				for (auto evt : mUserEvents)
				{
					delete evt;
				}
				mUserEvents.clear();

				mUserLock->unlock();
			}
		}
	}
	void AnalyticManager::sendBusinessEvents()
	{
		for (;;)
		{
			std::this_thread::sleep_for(std::chrono::seconds(SUBMIT_INTERVAL_SECONDS));

			if (mBusinessEvents.size() > 0 && mBusinessLock->try_lock())
			{
				std::vector<ProtocolBuffers::GameAnalytics::Event> messages;
				for (auto evt : mBusinessEvents)
				{
					evt->setParameters(mUID, mSID, mBuildIdentifier);
					messages.push_back(*evt->getMessage());
				}

				std::string rawJSON = ProtoJSON::asJSON(messages, ProtoJSON::FormatCompact, true);
				std::string authHeaderData = md5(rawJSON + mSecretKey);

				http::client::request req(getURL("design"));

				req << header("Authorization", authHeaderData);
				req << header("Content-Type", CONTENT_TYPE);
				req << header("Content-Length", std::to_string(rawJSON.length()));
				req << body(rawJSON);

				http::client::response resp = mClient->post(req);

				uint16_t r = status(resp);

				for (auto evt : mBusinessEvents)
				{
					delete evt;
				}
				mBusinessEvents.clear();

				mBusinessLock->unlock();
			}
		}
	}
	void AnalyticManager::sendDesignEvents()
	{
		for (;;)
		{
			std::this_thread::sleep_for(std::chrono::seconds(SUBMIT_INTERVAL_SECONDS));

			if (mDesignEvents.size() > 0 && mDesignLock->try_lock())
			{
				std::vector<ProtocolBuffers::GameAnalytics::Event> messages;
				for (auto evt : mDesignEvents)
				{
					evt->setParameters(mUID, mSID, mBuildIdentifier);
					messages.push_back(*evt->getMessage());
				}

				std::string rawJSON = ProtoJSON::asJSON(messages, ProtoJSON::FormatCompact, true);
				std::string authHeaderData = md5(rawJSON + mSecretKey);

				http::client::request req(getURL("design"));

				req << header("Authorization", authHeaderData);
				req << header("Content-Type", CONTENT_TYPE);
				req << header("Content-Length", std::to_string(rawJSON.length()));
				req << body(rawJSON);

				http::client::response resp = mClient->post(req);

				uint16_t r = status(resp);

				for (auto evt : mDesignEvents)
				{
					delete evt;
				}
				mDesignEvents.clear();

				mDesignLock->unlock();
			}
		}
	}
	void AnalyticManager::sendErrorEvents()
	{
		for (;;)
		{
			std::this_thread::sleep_for(std::chrono::seconds(SUBMIT_INTERVAL_SECONDS));

			if (mErrorEvents.size() > 0 && mErrorLock->try_lock())
			{
				std::vector<ProtocolBuffers::GameAnalytics::Event> messages;
				for (auto evt : mErrorEvents)
				{
					evt->setParameters(mUID, mSID, mBuildIdentifier);
					messages.push_back(*evt->getMessage());
				}

				std::string rawJSON = ProtoJSON::asJSON(messages, ProtoJSON::FormatCompact, true);
				std::string authHeaderData = md5(rawJSON + mSecretKey);

				http::client::request req(getURL("error"));

				req << header("Authorization", authHeaderData);
				req << header("Content-Type", CONTENT_TYPE);
				req << header("Content-Length", std::to_string(rawJSON.length()));
				req << body(rawJSON);

				http::client::response resp = mClient->post(req);

				uint16_t r = status(resp);

				std::cout << "Sent Error Events: " << mErrorEvents.size() << " status code " << r << std::endl;
				std::cout << "JSON\n" << rawJSON << std::endl;

				for (auto evt : mErrorEvents)
				{
					delete evt;
				}
				mErrorEvents.clear();

				mErrorLock->unlock();
			}
		}
	}
#pragma endregion

#pragma endregion

	void AnalyticManager::Queue(UserEvent* evt) 
	{ 
		mUserLock->lock();
		mUserEvents.push_back(evt); 
		mUserLock->unlock();
	}
	void AnalyticManager::Queue(BusinessEvent* evt) 
	{ 
		mBusinessLock->lock();
		mBusinessEvents.push_back(evt);
		mBusinessLock->unlock();
	}
	void AnalyticManager::Queue(DesignEvent* evt) 
	{
		mDesignLock->lock();
		mDesignEvents.push_back(evt);
		mDesignLock->unlock();
	}
	void AnalyticManager::Queue(ErrorEvent* evt) 
	{
		mErrorLock->lock();
		mErrorEvents.push_back(evt);
		mErrorLock->unlock();
	}

	std::string AnalyticManager::getURL(std::string category)
	{
		return (API_URL % API_VERSION % mGameKey % category).str();
	}

	bool AnalyticManager::mInitialized = false;
	std::shared_ptr<boost::network::http::client> AnalyticManager::mClient;

	std::thread AnalyticManager::mSubmitUE, AnalyticManager::mSubmitBE, AnalyticManager::mSubmitDE, AnalyticManager::mSubmitEE;
	std::shared_ptr<std::mutex> AnalyticManager::mUserLock, AnalyticManager::mBusinessLock, AnalyticManager::mDesignLock, AnalyticManager::mErrorLock;

	std::vector<UserEvent*> AnalyticManager::mUserEvents;
	std::vector<BusinessEvent*> AnalyticManager::mBusinessEvents;
	std::vector<DesignEvent*> AnalyticManager::mDesignEvents;
	std::vector<ErrorEvent*> AnalyticManager::mErrorEvents;

	std::string AnalyticManager::API_VERSION = "1";
	std::string AnalyticManager::CONTENT_TYPE = "application/json";
	boost::format AnalyticManager::API_URL("http://api.gameanalytics.com/%1%/%2%/%3%");
	int AnalyticManager::SUBMIT_INTERVAL_SECONDS = 15;

	std::string AnalyticManager::mAPIKey;
	std::string AnalyticManager::mGameKey;
	std::string AnalyticManager::mSecretKey;
	std::string AnalyticManager::mBuildIdentifier;
	std::string AnalyticManager::mSID;
	std::string AnalyticManager::mUID;
}