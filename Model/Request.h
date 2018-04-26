#pragma once

#include "RequestQueryStrings.h"

#include <string>
#include <vector>
#include <map>
#include <boost/optional.hpp>


namespace systelab { namespace web_server {

	class Request
	{
	public:
		Request();
		Request(const std::string& method,
				const std::string& uri,
				const std::map<std::string, std::string>& queryStrings,
				unsigned int httpVersionMajor,
				unsigned int httpVersionMinor,
				const std::map<std::string, std::string>& headers,
				const std::string& content);

		std::string getMethod() const;
		std::string getURI() const;
		unsigned int getHttpVersionMajor() const;
		unsigned int getHttpVersionMinor() const;
		std::string getContent() const;

		void setMethod(const std::string&);
		void setURI(const std::string&);
		void setHttpVersionMajor(unsigned int);
		void setHttpVersionMinor(unsigned int);
		void setContent(const std::string&);

		bool hasHeader(const std::string& name) const;
		std::string getHeader(const std::string& name) const;
		void addHeader(const std::string& name, const std::string& value);

		RequestQueryStrings& getQueryStrings();
		const RequestQueryStrings& getQueryStrings() const;

	private:
		std::string m_method;
		std::string m_uri;
		unsigned int m_httpVersionMajor;
		unsigned int m_httpVersionMinor;
		std::map<std::string, std::string> m_headers;
		RequestQueryStrings m_queryStrings;
		std::string m_content;
	};

}}
