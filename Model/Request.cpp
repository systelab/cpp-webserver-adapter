#include "stdafx.h"
#include "Request.h"

#include <sstream>
#include <regex>


namespace systelab { namespace web_server {

	Request::Request()
		:m_method("")
		,m_uri("")
		,m_queryStrings(RequestQueryStrings())
		,m_httpVersionMajor(1)
		,m_httpVersionMinor(1)
		,m_headers()
		,m_content("")
	{
	}

	Request::Request(const std::string& method,
					 const std::string& uri,
					 const std::map<std::string, std::string>& queryStrings,
					 unsigned int httpVersionMajor,
					 unsigned int httpVersionMinor,
					 const std::map<std::string, std::string>& headers,
					 const std::string& content)
		:m_method(method)
		,m_uri(uri)
		,m_queryStrings(RequestQueryStrings(queryStrings))
		,m_httpVersionMajor(httpVersionMajor)
		,m_httpVersionMinor(httpVersionMinor)
		,m_headers(headers)
		,m_content(content)
	{
	}

	std::string Request::getMethod() const
	{
		return m_method;
	}

	std::string Request::getURI() const
	{
		return m_uri;
	}

	unsigned int Request::getHttpVersionMajor() const
	{
		return m_httpVersionMajor;
	}

	unsigned int Request::getHttpVersionMinor() const
	{
		return m_httpVersionMinor;
	}

	std::string Request::getContent() const
	{
		return m_content;
	}

	void Request::setMethod(const std::string& method)
	{
		m_method = method;
	}

	void Request::setURI(const std::string& uri)
	{
		m_uri = uri;
	}

	void Request::setHttpVersionMajor(unsigned int httpVersionMajor)
	{
		m_httpVersionMajor = httpVersionMajor;
	}

	void Request::setHttpVersionMinor(unsigned int httpVersionMinor)
	{
		m_httpVersionMinor = httpVersionMinor;
	}

	void Request::setContent(const std::string& content)
	{
		m_content = content;
	}

	bool Request::hasHeader(const std::string& name) const
	{
		return (m_headers.find(name) != m_headers.end());
	}

	std::string Request::getHeader(const std::string& name) const
	{
		auto it = m_headers.find(name);
		if (m_headers.find(name) != m_headers.end())
		{
			return it->second;
		}
		else
		{
			std::string exc = std::string("Header '") + name + std::string("' not found.");
			throw std::exception(exc.c_str());
		}
	}

	void Request::addHeader(const std::string& name, const std::string& value)
	{
		m_headers.insert(std::make_pair(name, value));
	}

	RequestQueryStrings& Request::getQueryStrings()
	{
		return m_queryStrings;
	}

	const RequestQueryStrings& Request::getQueryStrings() const
	{
		return m_queryStrings;
	}

}}