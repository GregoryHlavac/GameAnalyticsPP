#pragma once

#include <mutex>
#include <vector>
#include <thread>
#include <string>
#include <memory>
#include <boost/format.hpp>
#include <boost/network/protocol/http/client.hpp>

namespace GameAnalytics
{
#pragma region Forward Declarations
	class Event;
	class UserEvent;
	class DesignEvent;
	class BusinessEvent;
	class ErrorEvent;
#pragma endregion Forward Declarations

	typedef std::shared_ptr<std::mutex> SPMutex;

	class AnalyticManager
	{
	public:
		static void Initialize(std::string secretKey, std::string gameKey, std::string apiKey, 
			std::string buildIdentifier, std::string userID = generateUserIdentifier(), std::string sessionID = generateSessionIdentifier());

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Send the event specified to the GameAnalytics Server.
		/// 	
		/// 	Keep in mind this is a blocking operation, so don't use it, if you might screw up your 
		/// </summary>
		///
		/// <param name="evt">	[in,out] If non-null, the event. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		static void Send(Event* evt);

		static void Queue(UserEvent* evt);
		static void Queue(BusinessEvent* evt);
		static void Queue(DesignEvent* evt);
		static void Queue(ErrorEvent* evt);
	private:
#pragma region Static Variables
		static boost::format API_URL;
		static std::string CONTENT_TYPE;
		static std::string API_VERSION;
		static int SUBMIT_INTERVAL_SECONDS;
#pragma endregion Static Variables

#pragma region Internal GameAnalytic Variables
		static std::string mSecretKey;
		static std::string mGameKey;
		static std::string mAPIKey;
		static std::string mBuildIdentifier;
		static std::string mUID;
		static std::string mSID;
#pragma endregion

#pragma region Analytic Manager Variables
		static bool mInitialized;
		static std::shared_ptr<boost::network::http::client> mClient;

		static std::thread mSubmitUE, mSubmitBE, mSubmitDE, mSubmitEE;
		static SPMutex mUserLock, mBusinessLock, mDesignLock, mErrorLock;

		static std::vector<UserEvent*> mUserEvents;
		static std::vector<BusinessEvent*> mBusinessEvents;
		static std::vector<DesignEvent*> mDesignEvents;
		static std::vector<ErrorEvent*> mErrorEvents;
#pragma endregion

#pragma region Batch Event Senders
		static void sendUserEvents();
		static void sendBusinessEvents();
		static void sendDesignEvents();
		static void sendErrorEvents();
#pragma endregion



		static std::string getURL(std::string category);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Generates a user identifier.
		/// 	
		/// 	This uses the user's MAC from network card.
		/// </summary>
		///
		/// <returns>
		/// 	The user identifier.
		/// </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		static std::string generateUserIdentifier();

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Generates a session identifier.
		/// 	
		/// 	This uses platform specific GUID generation code.
		/// 	
		/// 	In the case of windows this uses CoCreateGuid
		/// </summary>
		///
		/// <returns>
		/// 	The session identifier.
		/// </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		static std::string generateSessionIdentifier();
	};
}