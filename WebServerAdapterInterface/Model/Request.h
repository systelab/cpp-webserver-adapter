#pragma once

#include "RequestHeaders.h"
#include "RequestQueryStrings.h"
#include "Webserver/Request.h"
#include <string>
#include <vector>
#include <map>
#include <boost/optional.hpp>
#include <sstream>
#include <regex>

#include "Webserver/Request.h"

namespace systelab { namespace web_server {

	class Request
	{
	public:
		inline Request();
		inline Request(const std::string& method,
				const std::string& uri,
				const std::map<std::string, std::string>& queryStrings,
				unsigned int httpVersionMajor,
				unsigned int httpVersionMinor,
				const std::map<std::string, std::string>& headers,
				const std::string& content);

		inline std::string getMethod() const;
		inline std::string getURI() const;
		inline unsigned int getHttpVersionMajor() const;
		inline unsigned int getHttpVersionMinor() const;
		inline std::string getContent() const;

		inline void setMethod(const std::string&);
		inline void setURI(const std::string&);
		inline void setHttpVersionMajor(unsigned int);
		inline void setHttpVersionMinor(unsigned int);
		inline void setContent(const std::string&);

		inline RequestHeaders& getHeaders();
		inline const RequestHeaders& getHeaders() const;

		inline RequestQueryStrings& getQueryStrings();
		inline const RequestQueryStrings& getQueryStrings() const;
		static inline std::unique_ptr<systelab::web_server::Request> translateRequestToSystelabWebServer(const http::server::Request& request);

	private:
		std::string m_method;
		std::string m_uri;
		unsigned int m_httpVersionMajor;
		unsigned int m_httpVersionMinor;
		RequestHeaders m_headers;
		RequestQueryStrings m_queryStrings;
		std::string m_content;
	};

}}

#include "Request.inl"