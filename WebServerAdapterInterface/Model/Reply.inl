
namespace systelab { namespace web_server {

	Reply::Reply()
		:m_status(OK)
		,m_headers()
		,m_content("")
	{
	}

	Reply::Reply(StatusType status,
				 const std::map<std::string, std::string>& headers,
				 const std::string& content)
		:m_status(status)
		,m_headers(headers)
		,m_content(content)
	{
	}

	Reply::~Reply()
	{
	}

	Reply::StatusType Reply::getStatus() const
	{
		return m_status;
	}

	std::map<std::string, std::string> Reply::getHeaders() const
	{
		return m_headers;
	}

	bool Reply::hasHeader(const std::string& header) const
	{
		return (m_headers.find(header) != m_headers.end());
	}

	std::string Reply::getHeader(const std::string& name) const
	{
		auto it = m_headers.find(name);
		if (it != m_headers.end())
		{
			return it->second;
		}
		else
		{
			std::string exc = std::string("Header '") + name + std::string("' not found.");
			throw std::exception(exc.c_str());
		}
	}

	const std::string& Reply::getContent() const
	{
		return m_content;
	}

	void Reply::setStatus(StatusType status)
	{
		m_status = status;
	}

	void Reply::addHeader(const std::string& name, const std::string& value)
	{
		m_headers.insert(std::make_pair(name, value));
	}

	void Reply::setContent(const std::string& content)
	{
		m_content = content;
	}

	std::unique_ptr<http::server::Reply> Reply::translateReplyToHttpServer(std::unique_ptr<systelab::web_server::Reply> reply)
	{
		auto translatedReply = std::make_unique<http::server::Reply>();
		translatedReply->m_status = (http::server::Reply::StatusType) reply->getStatus();
		translatedReply->m_content = reply->getContent();

		auto headers = reply->getHeaders();
		for (auto header : headers)
		{
			translatedReply->setHeader(header.first, header.second);
		}

		return translatedReply;
	}

	std::unique_ptr<systelab::web_server::Reply> Reply::translateReplyToSystelabWebServer(std::unique_ptr<http::server::Reply> reply)
	{
		systelab::web_server::Reply::StatusType status = static_cast<systelab::web_server::Reply::StatusType>((unsigned int)reply->getStatus());
		std::map<std::string, std::string> headers = reply->getHeaders();
		const std::string content = reply->getContent();
		
		return std::make_unique<systelab::web_server::Reply>(status, headers, content);
	}

}}
