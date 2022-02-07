
namespace systelab { namespace web_server {

	SecurityConfiguration::SecurityConfiguration()
		:m_httpsEnabled(false)
		,m_serverCertificate([](){ return std::string(""); })
		,m_serverPrivateKey([](){ return std::string(""); })
		,m_serverDHParam([](){ return std::string(""); })
		,m_mutualSSLEnabled(false)
		,m_clientCertificate("")
		,m_tlsv10Enabled(false)
		,m_tlsv11Enabled(false)
		,m_tlsv12Enabled(true)
		,m_tlsv13Enabled(false)
	{
	}

	SecurityConfiguration::SecurityConfiguration(const SecurityConfiguration& other)
		:m_httpsEnabled(other.m_httpsEnabled)
		,m_serverCertificate(other.m_serverCertificate)
		,m_serverPrivateKey(other.m_serverPrivateKey)
		,m_serverDHParam(other.m_serverDHParam)
		,m_mutualSSLEnabled(other.m_mutualSSLEnabled)
		,m_clientCertificate(other.m_clientCertificate)
		,m_tlsv10Enabled(other.m_tlsv10Enabled)
		,m_tlsv11Enabled(other.m_tlsv11Enabled)
		,m_tlsv12Enabled(other.m_tlsv12Enabled)
		,m_tlsv13Enabled(other.m_tlsv13Enabled)
	{
	}

	SecurityConfiguration::~SecurityConfiguration() = default;

	bool SecurityConfiguration::isHTTPSEnabled() const
	{
		return m_httpsEnabled;
	}

	std::function<std::string()> SecurityConfiguration::getServerCertificate() const
	{
		return m_serverCertificate;
	}

	std::function<std::string()> SecurityConfiguration::getServerPrivateKey() const
	{
		return m_serverPrivateKey;
	}

	std::function<std::string()> SecurityConfiguration::getServerDHParam() const
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

	bool SecurityConfiguration::isTLSv10Enabled() const
	{
		return m_tlsv10Enabled;
	}

	bool SecurityConfiguration::isTLSv11Enabled() const
	{
		return m_tlsv11Enabled;
	}

	bool SecurityConfiguration::isTLSv12Enabled() const
	{
		return m_tlsv12Enabled;
	}

	bool SecurityConfiguration::isTLSv13Enabled() const
	{
		return m_tlsv13Enabled;
	}

	void SecurityConfiguration::setHTTPSEnabled(bool httpsEnabled)
	{
		m_httpsEnabled = httpsEnabled;
	}

	void SecurityConfiguration::setServerCertificate(const std::function<std::string()>& serverCertificate)
	{
		m_serverCertificate = serverCertificate;
	}

	void SecurityConfiguration::setServerPrivateKey(const std::function<std::string()>& serverPrivateKey)
	{
		m_serverPrivateKey = serverPrivateKey;
	}

	void SecurityConfiguration::setServerDHParam(const std::function<std::string()>& serverDHParam)
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

	void SecurityConfiguration::setTLSv10Enabled(bool tlsv10Enabled)
	{
		m_tlsv10Enabled = tlsv10Enabled;
	}
	
	void SecurityConfiguration::setTLSv11Enabled(bool tlsv11Enabled)
	{
		m_tlsv11Enabled = tlsv11Enabled;
	}
	
	void SecurityConfiguration::setTLSv12Enabled(bool tlsv12Enabled)
	{
		m_tlsv12Enabled = tlsv12Enabled;
	}
	
	void SecurityConfiguration::setTLSv13Enabled(bool tlsv13Enabled)
	{
		m_tlsv13Enabled = tlsv13Enabled;
	}

	SecurityConfiguration& SecurityConfiguration::operator= (const SecurityConfiguration& other)
	{
		m_httpsEnabled = other.m_httpsEnabled;
		m_serverCertificate = other.m_serverCertificate;
		m_serverPrivateKey = other.m_serverPrivateKey;
		m_serverDHParam = other.m_serverDHParam;
		m_mutualSSLEnabled = other.m_mutualSSLEnabled;
		m_clientCertificate = other.m_clientCertificate;
		m_tlsv10Enabled = other.m_tlsv10Enabled;
		m_tlsv11Enabled = other.m_tlsv11Enabled;
		m_tlsv12Enabled = other.m_tlsv12Enabled;
		m_tlsv13Enabled = other.m_tlsv13Enabled;

		return *this;
	}

}}