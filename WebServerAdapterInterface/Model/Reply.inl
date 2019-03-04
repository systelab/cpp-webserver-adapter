
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

	Reply::~Reply() = default;

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
			throw std::runtime_error(exc.c_str());
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

}}
