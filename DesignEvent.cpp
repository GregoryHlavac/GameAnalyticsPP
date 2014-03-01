#include "stdafx.h"
#include "DesignEvent.h"

#include "DesignEvent.pb.h"

namespace GameAnalytics
{
	DesignEvent::DesignEvent() {}
	DesignEvent::~DesignEvent() {}

	std::string DesignEvent::getCategory()
	{
		return "error";
	}

	void DesignEvent::setValue(float val)
	{

	}
}