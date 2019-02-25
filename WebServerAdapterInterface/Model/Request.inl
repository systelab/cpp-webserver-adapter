
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

	RequestHeaders& Request::getHeaders()
	{
		return m_headers;
	}

	const RequestHeaders& Request::getHeaders() const
	{
		return m_headers;
	}

	RequestQueryStrings& Request::getQueryStrings()
	{
		return m_queryStrings;
	}

	const RequestQueryStrings& Request::getQueryStrings() const
	{
		return m_queryStrings;
	}

	std::unique_ptr<systelab::web_server::Request> Request::translateRequestToSystelabWebServer(const http::server::Request& request)
	{
		auto translatedRequest = std::make_unique<systelab::web_server::Request>();
		translatedRequest->setURI(request.uri);
		translatedRequest->setMethod(request.method);
		translatedRequest->setContent(request.content);
		translatedRequest->setHttpVersionMajor(request.http_version_major);
		translatedRequest->setHttpVersionMinor(request.http_version_minor);

		auto& translatedQueryStrings = translatedRequest->getQueryStrings();
		for (const auto& queryString : request.m_queryStrings)
		{
			translatedQueryStrings.addItem(queryString.first, queryString.second);
		}

		auto& translatedHeaders = translatedRequest->getHeaders();
		for (const auto& header : request.headers)
		{
			translatedHeaders.addHeader(header.first, header.second);
		}

		return translatedRequest;
	}

}}