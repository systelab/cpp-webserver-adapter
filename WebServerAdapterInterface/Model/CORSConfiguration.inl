
namespace systelab { namespace web_server {

	CORSConfiguration::CORSConfiguration()
		:m_enabled(false)
		,m_allowedOrigins()
		,m_allowedHeaders("")
		,m_allowedMethods("")
		,m_allowedCredentials(false)
		,m_maxAge(0)
		,m_exposedHeaders("")
	{
	}

	CORSConfiguration::CORSConfiguration(const CORSConfiguration& other)
		:m_enabled(other.m_enabled)
		,m_allowedOrigins(other.m_allowedOrigins)
		,m_allowedHeaders(other.m_allowedHeaders)
		,m_allowedMethods(other.m_allowedMethods)
		,m_allowedCredentials(other.m_allowedCredentials)
		,m_maxAge(other.m_maxAge)
		,m_exposedHeaders(other.m_exposedHeaders)
	{
	}

	CORSConfiguration::~CORSConfiguration()
	{
	}

	bool CORSConfiguration::isEnabled() const
	{
		return m_enabled;
	}

	bool CORSConfiguration::isAllowedOrigin(const std::string& allowedOrigin) const
	{
		return (m_allowedOrigins.count(allowedOrigin) > 0) || (m_allowedOrigins.count("*") > 0);
	}

	std::string CORSConfiguration::getAllowedHeaders() const
	{
		return m_allowedHeaders;
	}

	std::string CORSConfiguration::getAllowedMethods() const
	{
		return m_allowedMethods;
	}

	bool CORSConfiguration::areAllowedCredentials() const
	{
		return m_allowedCredentials;
	}

	unsigned int CORSConfiguration::getMaxAge() const
	{
		return m_maxAge;
	}
	
	std::string CORSConfiguration::getExposedHeaders() const
	{
		return m_exposedHeaders;
	}

	void CORSConfiguration::setEnabled(bool enabled)
	{
		m_enabled = enabled;
	}

	void CORSConfiguration::addAllowedOrigin(const std::string& allowedOrigin)
	{
		m_allowedOrigins.insert(allowedOrigin);
	}

	void CORSConfiguration::setAllowedHeaders(const std::string& allowedHeaders)
	{
		m_allowedHeaders = allowedHeaders;
	}

	void CORSConfiguration::setAllowedMethods(const std::string& allowedMethods)
	{
		m_allowedMethods = allowedMethods;
	}

	void CORSConfiguration::setAllowedCredentials(bool allowedCredentials)
	{
		m_allowedCredentials = allowedCredentials;
	}

	void CORSConfiguration::setMaxAge(unsigned int maxAge)
	{
		m_maxAge = maxAge;
	}

	void CORSConfiguration::setExposedHeaders(const std::string& expostedHeaders)
	{
		m_exposedHeaders = expostedHeaders;
	}

	CORSConfiguration& CORSConfiguration::operator= (const CORSConfiguration& other)
	{
		m_enabled = other.m_enabled;
		m_allowedOrigins = other.m_allowedOrigins;
		m_allowedHeaders = other.m_allowedHeaders;
		m_allowedMethods = other.m_allowedMethods;
		m_allowedCredentials = other.m_allowedCredentials;
		m_maxAge = other.m_maxAge;
		m_exposedHeaders = other.m_exposedHeaders;

		return *this;
	}

}}
