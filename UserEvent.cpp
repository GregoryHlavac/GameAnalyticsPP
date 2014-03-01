#include "stdafx.h"
#include "UserEvent.h"

#include "UserEvent.pb.h"

namespace GameAnalytics
{
	UserEvent::UserEvent() {}
	UserEvent::~UserEvent() {}

	std::string UserEvent::getCategory()
	{
		return "user";
	}

	void UserEvent::setGender(char gender) 
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::gender, std::to_string(gender));
	}
	void UserEvent::setBirthYear(int year)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::birth_year, year);
	}
	void UserEvent::setFriendCount(int count)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::friend_count, count);
	}
	void UserEvent::setFacebookID(std::string fbID)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::facebook_id, fbID);
	}
	void UserEvent::setGooglePlusID(std::string gpID)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::googleplus_id, gpID);
	}
	void UserEvent::setIOSID(std::string iosID)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::ios_id, iosID);
	}
	void UserEvent::setAndroidID(std::string androidID)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::android_id, androidID);
	}
	void UserEvent::setAdTruthID(std::string adTruthID)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::adtruth_id, adTruthID);
	}
	void UserEvent::setPlatform(std::string platform)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::platform, platform);
	}
	void UserEvent::setDevice(std::string device)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::device, device);
	}
	void UserEvent::setOSMajor(std::string majVersion)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::os_major, majVersion);
	}
	void UserEvent::setOSMinor(std::string minVersion)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::os_minor, minVersion);
	}
	void UserEvent::setInstallationPublisher(std::string pub)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_publisher, pub);
	}
	void UserEvent::setInstallSite(std::string instSite)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_site, instSite);
	}
	void UserEvent::setCampaign(std::string campaign)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_campaign, campaign);
	}
	void UserEvent::setAdGroup(std::string adgrp)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_adgroup, adgrp);
	}
	void UserEvent::setInstallAD(std::string instad)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_ad, instad);
	}
	void UserEvent::setKeyword(std::string kw)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::UserEvent::install_keyword, kw);
	}
}