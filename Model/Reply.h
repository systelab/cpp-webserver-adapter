#pragma once

#include <string>
#include <vector>
#include <boost/asio.hpp>


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

		Reply();
		Reply(StatusType status,
			  const std::map<std::string, std::string>& headers,
			  const std::string& content);
		virtual ~Reply();

		StatusType getStatus() const;
		std::map<std::string, std::string> getHeaders() const;
		std::string getHeader(const std::string& header) const;
		const std::string& getContent() const;

		void setStatus(StatusType);
		void addHeader(const std::string& header, const std::string& value);
		void setContent(const std::string&);

	protected:
		StatusType m_status;
		std::map<std::string, std::string> m_headers;
		std::string m_content;
	};

}}

