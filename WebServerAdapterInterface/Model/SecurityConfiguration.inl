
namespace systelab { namespace web_server {

	SecurityConfiguration::SecurityConfiguration()
		:m_httpsEnabled(false)
		,m_serverCertificate("")
		,m_serverPrivateKey("")
		,m_serverDHParam("")
		,m_mutualSSLEnabled(false)
		,m_clientCertificate("")
	{
	}

	SecurityConfiguration::~SecurityConfiguration() = default;

	bool SecurityConfiguration::isHTTPSEnabled() const
	{
		return m_httpsEnabled;
	}

	std::string SecurityConfiguration::getServerCertificate() const
	{
		return m_serverCertificate;
	}

	std::string SecurityConfiguration::getServerPrivateKey() const
	{
		return m_serverPrivateKey;
	}

	std::string SecurityConfiguration::getServerDHParam() const
	{
		return m_serverDHParam;
	}

	bool SecurityConfiguration::isMutualSSLEnabled() const
	{
		return m_mutualSSLEnabled;
	}

	std::string SecurityConfiguration::getClientCertificate() const
	{
		return m_clientCertificate;
	}

	void SecurityConfiguration::setHTTPSEnabled(bool httpsEnabled)
	{
		m_httpsEnabled = httpsEnabled;
	}

	void SecurityConfiguration::setServerCertificate(const std::string& serverCertificate)
	{
		m_serverCertificate = serverCertificate;
	}

	void SecurityConfiguration::setServerPrivateKey(const std::string& serverPrivateKey)
	{
		m_serverPrivateKey = serverPrivateKey;
	}

	void SecurityConfiguration::setServerDHParam(const std::string& serverDHParam)
	{
		m_serverDHParam = serverDHParam;
	}

	void SecurityConfiguration::setMutualSSLEnabled(bool mutualSSLEnabled)
	{
		m_mutualSSLEnabled = mutualSSLEnabled;
	}

	void SecurityConfiguration::setClientCertificate(const std::string& clientCertificate)
	{
		m_clientCertificate = clientCertificate;
	}

	SecurityConfiguration& SecurityConfiguration::operator= (const SecurityConfiguration& other)
	{
		m_httpsEnabled = other.m_httpsEnabled;
		m_serverCertificate = other.m_serverCertificate;
		m_serverPrivateKey = other.m_serverPrivateKey;
		m_serverDHParam = other.m_serverDHParam;
		m_mutualSSLEnabled = other.m_mutualSSLEnabled;
		m_clientCertificate = other.m_clientCertificate;

		return *this;
	}

}}