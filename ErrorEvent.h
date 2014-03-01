#pragma once
#include "Event.h"

namespace GameAnalytics
{
	enum class ErrorSeverity
	{
		Info,
		Debug,
		Warning,
		Error,
		Critical
	};

	class ErrorEvent : public Event
	{
	public:
		ErrorEvent();
		~ErrorEvent();

		virtual std::string getCategory();

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Sets a message.
		/// 	
		/// 	Used to describe the event in further detail. For example, in the case of an exception the event could contain the stack trace.
		/// </summary>
		///
		/// <param name="msg">	The message. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		void setMessage(std::string msg);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Sets the severity of the error event.
		/// </summary>
		///
		/// <param name="es">	The es. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		void setSeverity(ErrorSeverity es);
	};
}




