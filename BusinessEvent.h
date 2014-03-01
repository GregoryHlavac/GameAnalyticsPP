#pragma once
#include "Event.h"

namespace GameAnalytics
{
	class BusinessEvent : public Event
	{
	public:
		BusinessEvent();
		~BusinessEvent();

		virtual std::string getCategory();

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Sets a currency.
		/// 	
		/// 	A custom string for identifying the currency. For example "USD", "US Dollars" or "GA Dollars".
		/// </summary>
		///
		/// <param name="cur">	The current. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		void setCurrency(std::string cur);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Sets an amount.
		/// 	
		/// 	Numeric value which corresponds to the cost of the purchase in the monetary unit multiplied by 100. 
		/// 	For example, if the currency is "USD", the amount should be specified in cents.
		/// </summary>
		///
		/// <param name="amt">	The amount. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		void setAmount(int amt);
	};
}