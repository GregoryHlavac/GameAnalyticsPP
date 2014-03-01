#include "stdafx.h"
#include "ErrorEvent.h"

#include "ErrorEvent.pb.h"

namespace GameAnalytics
{
	ErrorEvent::ErrorEvent() {}
	ErrorEvent::~ErrorEvent() {}

	std::string ErrorEvent::getCategory()
	{
		return "error";
	}

	void ErrorEvent::setMessage(std::string msg)
	{
		mData.SetExtension(ProtocolBuffers::GameAnalytics::ErrorEvent::message, msg);
	}

	void ErrorEvent::setSeverity(ErrorSeverity es)
	{
		std::string sev;

		switch (es)
		{
		case GameAnalytics::ErrorSeverity::Info:
			sev = "info";
			break;
		case GameAnalytics::ErrorSeverity::Debug:
			sev = "debug";
			break;
		case GameAnalytics::ErrorSeverity::Warning:
			sev = "warning";
			break;
		case GameAnalytics::ErrorSeverity::Error:
			sev = "error";
			break;
		case GameAnalytics::ErrorSeverity::Critical:
			sev = "critical";
			break;
		default:
			sev = "info";
			break;
		}

		mData.SetExtension(ProtocolBuffers::GameAnalytics::ErrorEvent::severity, sev);
	}
}