#pragma once

#include "WebServerAdapterInterface/Model/Request.h"


namespace systelab { namespace web_server { namespace test_utility {

	class RequestBuilder
	{
	public:
		RequestBuilder();
		virtual ~RequestBuilder();

		RequestBuilder& setMethod(const std::string&);
		RequestBuilder& setURI(const std::string&);
		RequestBuilder& setURIFull(const std::string&);
		RequestBuilder& setHttpVersionMajor(unsigned int);
		RequestBuilder& setHttpVersionMinor(unsigned int);
		RequestBuilder& setContent(const std::string&);

		RequestBuilder& setHeaders(const RequestHeaders&);
		RequestBuilder& setQueryStrings(const RequestQueryStrings&);

		Request getEntity() const;

	private:
		Request m_request;
	};

}}}

