#pragma once

#include <map>
#include <string>
#include <vector>


namespace systelab { namespace web_server {

	class Reply
	{
	public:
		enum StatusType
		{
			OK = 200,
			CREATED = 201,
			ACCEPTED = 202,
			NO_CONTENT = 204,
			MULTI_STATUS = 207,
			MULTIPLE_CHOICES = 300,
			MOVED_PERMANENTLY = 301,
			MOVED_TEMPORARILY = 302,
			NOT_MODIFIED = 304,
			BAD_REQUEST = 400,
			UNAUTHORIZED = 401,
			FORBIDDEN = 403,
			NOT_FOUND = 404,
			REQUEST_TIMEOUT = 408,
			INTERNAL_SERVER_ERROR = 500,
			NOT_IMPLEMENTED = 501,
			BAD_GATEWAY = 502,
			SERVICE_UNAVAILABLE = 503
		};

		inline Reply();
		inline Reply(StatusType status,
					 const std::map<std::string, std::string>& headers,
					 const std::string& content);
		inline virtual ~Reply();

		inline StatusType getStatus() const;
		inline std::map<std::string, std::string> getHeaders() const;
		inline bool hasHeader(const std::string& header) const;
		inline std::string getHeader(const std::string& header) const;
		inline const std::string& getContent() const;

		inline void setStatus(StatusType);
		inline void addHeader(const std::string& header, const std::string& value);
		inline void setContent(const std::string&);

	protected:
		StatusType m_status;
		std::map<std::string, std::string> m_headers;
		std::string m_content;
	};

}}

#include "Reply.inl"

