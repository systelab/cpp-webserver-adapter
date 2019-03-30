#pragma once

#include "WebServerAdapterInterface/Model/RequestQueryStrings.h"


namespace systelab { namespace web_server { namespace test_utility {

	class RequestQueryStringsBuilder
	{
	public:
		RequestQueryStringsBuilder();
		virtual ~RequestQueryStringsBuilder();

		RequestQueryStringsBuilder& addItem(const std::string& name, const std::string& value);

		RequestQueryStrings getEntity() const;

	private:
		RequestQueryStrings m_requestQueryStrings;
	};

}}}

