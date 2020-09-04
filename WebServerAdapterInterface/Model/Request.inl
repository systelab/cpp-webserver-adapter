
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
1					 const std::string& content)
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

	std::string Request::getURIWithQueryStrings() const
	{
		std::stringstream ss;
		ss << m_uri;

		auto queryStringsMap = m_queryStrings.getItemsMap();
		if (queryStringsMap.size() > 0)
		{
			bool firstQueryString = true;
			for (auto queryString : queryStringsMap)
			{
				ss << (firstQueryString ? "?" : "&");
				ss << queryString.first + "=" + queryString.second;
				firstQueryString = false;
			}
		}

		return ss.str();
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

	RequestHeaders& Request::getHeaders()
	{
		return m_headers;
	}

	const RequestHeaders& Request::getHeaders() const
	{
		return m_headers;
	}

	void Request::setHeaders(const RequestHeaders& headers)
	{
		m_headers = headers;
	}
	
	RequestQueryStrings& Request::getQueryStrings()
	{
		return m_queryStrings;
	}

	const RequestQueryStrings& Request::getQueryStrings() const
	{
		return m_queryStrings;
	}

	void Request::setQueryStrings(const RequestQueryStrings& queryStrings)
	{
		m_queryStrings = queryStrings;
	}

}}

