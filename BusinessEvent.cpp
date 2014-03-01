#include "stdafx.h"
#include "BusinessEvent.h"

#include "BusinessEvent.pb.h"

namespace GameAnalytics
{
	BusinessEvent::BusinessEvent() {}
	BusinessEvent::~BusinessEvent() {}

	std::string BusinessEvent::getCategory()
	{
		return "business";
	}

	void BusinessEvent::setCurrency(std::string cur)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::BusinessEvent::currency, cur);
	}

	void BusinessEvent::setAmount(int amt)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::BusinessEvent::amount, amt);
	}
}