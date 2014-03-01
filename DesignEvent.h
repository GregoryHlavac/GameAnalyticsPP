#pragma once
#include "Event.h"

namespace GameAnalytics
{
	class DesignEvent : public Event
	{
	public:
		DesignEvent();
		~DesignEvent();

		virtual std::string getCategory();

		void setValue(float val);
	};
}




