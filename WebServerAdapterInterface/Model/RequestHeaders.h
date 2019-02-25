#pragma once

#include <string>
#include <map>


namespace systelab { namespace web_server {

	class RequestHeaders
	{
	public:
		inline RequestHeaders();
		inline RequestHeaders(const std::map<std::string, std::string>&);
		inline virtual ~RequestHeaders();

		inline bool hasHeader(const std::string& name) const;
		inline std::string getHeader(const std::string& name) const;
		inline std::map<std::string, std::string> getHeadersMap() const;

		inline void addHeader(const std::string& name, const std::string& value);

	private:
		std::map<std::string, std::string> m_headers;
	};

}}

#include "RequestHeaders.inl"