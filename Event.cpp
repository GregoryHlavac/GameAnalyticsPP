#include "stdafx.h"
#include "Event.h"

#include <ProtoJSON.h>

namespace GameAnalytics
{
	Event::Event() {}

	Event::~Event() {}

	std::string Event::constructJSON(std::string uid, std::string sid, std::string build)
	{
		mData.set_user_id(uid);
		mData.set_session_id(sid);
		mData.set_build(build);

		return ProtoJSON::asJSON(mData, ProtoJSON::FormatCompact, true);
	}

	void Event::setIdentifier(std::string id)
	{
		mData.set_event_id(id);
	}
	void Event::setArea(std::string area)
	{
		mData.set_area(area);
	}
	void Event::setX(float x)
	{
		mData.set_x(x);
	}
	void Event::setY(float y)
	{
		mData.set_y(y);
	}
	void Event::setZ(float z)
	{
		mData.set_z(z);
	}

	void Event::setParameters(std::string uid, std::string sid, std::string build)
	{
		mData.set_user_id(uid);
		mData.set_session_id(sid);
		mData.set_build(build);
	}

	ProtocolBuffers::GameAnalytics::Event* Event::getMessage()
	{
		return &mData;
	}

	Event::operator ProtocolBuffers::GameAnalytics::Event() const
	{
		return mData;
	}

}
