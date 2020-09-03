#pragma once

#include "RequestHeaders.h"
#include "RequestQueryStrings.h"


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
		inline std::string getURIFull() const;
		inline unsigned int getHttpVersionMajor() const;
		inline unsigned int getHttpVersionMinor() const;
		inline std::string getContent() const;

		inline void setMethod(const std::string&);
		inline void setURI(const std::string&);
		inline void setURIFull(const std::string&);
		inline void setHttpVersionMajor(unsigned int);
		inline void setHttpVersionMinor(unsigned int);
		inline void setContent(const std::string&);

		inline RequestHeaders& getHeaders();
		inline const RequestHeaders& getHeaders() const;
		inline void setHeaders(const RequestHeaders&);

		inline RequestQueryStrings& getQueryStrings();
		inline const RequestQueryStrings& getQueryStrings() const;
		inline void setQueryStrings(const RequestQueryStrings&);

	private:
		std::string m_method;
		std::string m_uri;
		std::string m_uriFull;
		unsigned int m_httpVersionMajor;
		unsigned int m_httpVersionMinor;
		RequestHeaders m_headers;
		RequestQueryStrings m_queryStrings;
		std::string m_content;
	};

}}

#include "Request.inl"
