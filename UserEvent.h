#pragma once
#include "Event.h"

namespace GameAnalytics
{
	class UserEvent : public Event
	{
	public:
		UserEvent();
		~UserEvent();

		virtual std::string getCategory();

		void setGender(char gender);
		void setBirthYear(int year);
		void setFriendCount(int count);
		void setFacebookID(std::string fbID);
		void setGooglePlusID(std::string gpID);
		void setIOSID(std::string iosID);
		void setAndroidID(std::string androidID);
		void setAdTruthID(std::string adTruthID);
		void setPlatform(std::string platform);
		void setDevice(std::string device);
		void setOSMajor(std::string majVersion);
		void setOSMinor(std::string minVersion);
		void setInstallationPublisher(std::string pub);
		void setInstallSite(std::string instSite);
		void setCampaign(std::string campaign);
		void setAdGroup(std::string adgrp);
		void setInstallAD(std::string instad);
		void setKeyword(std::string kw);
	};
}




