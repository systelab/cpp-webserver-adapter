
namespace systelab { namespace web_server {

	CORSConfiguration::CORSConfiguration()
		:m_enabled(false)
		,m_allowedOrigins()
		,m_allowedMethods()
		,m_allowedHeaders()
		,m_exposedHeaders()
		,m_allowedCredentials(false)
		,m_maxAge(0)
	{
	}

	CORSConfiguration::CORSConfiguration(const CORSConfiguration& other)
		:m_enabled(other.m_enabled)
		,m_allowedOrigins(other.m_allowedOrigins)
		,m_allowedMethods(other.m_allowedMethods)
		,m_allowedHeaders(other.m_allowedHeaders)
		,m_exposedHeaders(other.m_exposedHeaders)
		,m_allowedCredentials(other.m_allowedCredentials)
		,m_maxAge(other.m_maxAge)
	{
	}

	CORSConfiguration::~CORSConfiguration() = default;

	bool CORSConfiguration::isEnabled() const
	{
		return m_enabled;
	}

	void CORSConfiguration::setEnabled(bool enabled)
	{
		m_enabled = enabled;
	}

	bool CORSConfiguration::isAllowedOrigin(const std::string& origin) const
	{
		return (m_allowedOrigins.count(origin) > 0) || (m_allowedOrigins.count("*") > 0);
	}

	std::set<std::string> CORSConfiguration::getAllowedOrigins() const
	{
		return m_allowedOrigins;
	}

	void CORSConfiguration::addAllowedOrigin(const std::string& allowedOrigin)
	{
		m_allowedOrigins.insert(allowedOrigin);
	}

	void CORSConfiguration::setAllowedOrigins(const std::set<std::string>& allowedOrigins)
	{
		m_allowedOrigins = allowedOrigins;
	}

	bool CORSConfiguration::isAllowedMethod(const std::string& method) const
	{
		return (m_allowedMethods.count(method) > 0) || (m_allowedMethods.count("*") > 0);
	}

	std::set<std::string> CORSConfiguration::getAllowedMethods() const
	{
		return m_allowedMethods;
	}

	void CORSConfiguration::addAllowedMethod(const std::string& allowedMethod)
	{
		m_allowedMethods.insert(allowedMethod);
	}

	void CORSConfiguration::setAllowedMethods(const std::set<std::string>& allowedMethods)
	{
		m_allowedMethods = allowedMethods;
	}

	bool CORSConfiguration::isAllowedHeader(const std::string& header) const
	{
		return (m_allowedHeaders.count(header) > 0) || (m_allowedHeaders.count("*") > 0);
	}

	std::set<std::string> CORSConfiguration::getAllowedHeaders() const
	{
		return m_allowedHeaders;
	}

	void CORSConfiguration::addAllowedHeader(const std::string& allowedHeader)
	{
		m_allowedHeaders.insert(allowedHeader);
	}

	void CORSConfiguration::setAllowedHeaders(const std::set<std::string>& allowedHeaders)
	{
		m_allowedHeaders = allowedHeaders;
	}

	bool CORSConfiguration::isExposedHeader(const std::string& header) const
	{
		return (m_exposedHeaders.count(header) > 0) || (m_exposedHeaders.count("*") > 0);
	}

	std::set<std::string> CORSConfiguration::getExposedHeaders() const
	{
		return m_exposedHeaders;
	}

	void CORSConfiguration::addExposedHeader(const std::string& exposedHeader)
	{
		m_exposedHeaders.insert(exposedHeader);
	}

	void CORSConfiguration::setExposedHeaders(const std::set<std::string>& expostedHeaders)
	{
		m_exposedHeaders = expostedHeaders;
	}

	bool CORSConfiguration::areAllowedCredentials() const
	{
		return m_allowedCredentials;
	}

	void CORSConfiguration::setAllowedCredentials(bool allowedCredentials)
	{
		m_allowedCredentials = allowedCredentials;
	}

	unsigned int CORSConfiguration::getMaxAge() const
	{
		return m_maxAge;
	}

	void CORSConfiguration::setMaxAge(unsigned int maxAge)
	{
		m_maxAge = maxAge;
	}

	CORSConfiguration& CORSConfiguration::operator= (const CORSConfiguration& other)
	{
		m_enabled = other.m_enabled;
		m_allowedOrigins = other.m_allowedOrigins;
		m_allowedMethods = other.m_allowedMethods;
		m_allowedHeaders = other.m_allowedHeaders;
		m_exposedHeaders = other.m_exposedHeaders;
		m_allowedCredentials = other.m_allowedCredentials;
		m_maxAge = other.m_maxAge;

		return *this;
	}

}}
