#pragma once

#include <mutex>
#include <vector>
#include <thread>
#include <memory>

#include "Event.h"

#include <boost/network/protocol/http/client.hpp>

using std::mutex;
using std::shared_ptr;

using namespace boost::network;
using namespace boost::network::http;

namespace GameAnalytics
{
	template <typename T>
	typename std::enable_if<std::is_base_of<Event, T>::value, void>::type
		SubmitEvents(std::shared_ptr<boost::network::http::client> client, std::shared_ptr<std::mutex> mtx,
						std::vector<T*> events, int delay, std::string eventType, 
							std::string uid, std::string sid, std::string build)
	{
			for (;;)
			{
				std::this_thread::sleep_for(std::chrono::seconds(delay));

				if (events.size() > 0 && mtx->try_lock())
				{
					std::string evtString = "[";

					for (int i = 0; i < events.size(); i++)
					{
						evtString += events[i]->constructJSON(uid, sid, build);

						if (i != events.size() - 1)
							evtString += ",";
					}

					evtString += "]";

					std::string rawJSON = evtString;
					std::string authHeaderData = md5(rawJSON + mSecretKey);

					http::client::request req(getURL(eventType));

					req << header("Authorization", authHeaderData);
					req << header("Content-Type", CONTENT_TYPE);
					req << header("Content-Length", std::to_string(rawJSON.length()));
					req << body(rawJSON);

					http::client::response resp = mClient->post(req);

					uint16_t r = status(resp);

					std::cout << "Response Status: " << r << std::endl;


					for (auto evt : events)
					{
						delete evt;
					}
					events.clear();

					mtx->unlock();
				}
			}
	}
}