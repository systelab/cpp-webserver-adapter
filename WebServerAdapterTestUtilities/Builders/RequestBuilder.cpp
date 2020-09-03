#include "RequestBuilder.h"


namespace systelab { namespace web_server { namespace test_utility {

	RequestBuilder::RequestBuilder()
		:m_request()
	{
	}

	RequestBuilder::~RequestBuilder() = default;

	RequestBuilder& RequestBuilder::setMethod(const std::string& method)
	{
		m_request.setMethod(method);
		return *this;
	}

	RequestBuilder& RequestBuilder::setURI(const std::string& uri)
	{
		m_request.setURI(uri);
		return *this;
	}

	RequestBuilder& RequestBuilder::setURIFull(const std::string& uriFull)
	{
		m_request.setURIFull(uriFull);
		return *this;
	}

	RequestBuilder& RequestBuilder::setHttpVersionMajor(unsigned int httpVersionMajor)
	{
		m_request.setHttpVersionMajor(httpVersionMajor);
		return *this;
	}

	RequestBuilder& RequestBuilder::setHttpVersionMinor(unsigned int httpVersionMinor)
	{
		m_request.setHttpVersionMinor(httpVersionMinor);
		return *this;
	}

	RequestBuilder& RequestBuilder::setContent(const std::string& content)
	{
		m_request.setContent(content);
		return *this;
	}

	RequestBuilder& RequestBuilder::setHeaders(const RequestHeaders& headers)
	{
		m_request.setHeaders(headers);
		return *this;
	}

	RequestBuilder& RequestBuilder::setQueryStrings(const RequestQueryStrings& queryStrings)
	{
		m_request.setQueryStrings(queryStrings);
		return *this;
	}

	Request RequestBuilder::getEntity() const
	{
		return m_request;
	}

}}}
