#include "CORSConfiguration.h"
#include "SecurityConfiguration.h"


namespace systelab { namespace web_server {

	Configuration::Configuration()
		:m_singleHostAddress(true)
		,m_hostAddress("127.0.0.1")
		,m_port(80)
		,m_threadPoolSize(1)
		,m_corsConfiguration(std::make_unique<CORSConfiguration>())
		,m_securityConfiguration(std::make_unique<SecurityConfiguration>())
	{
	}

	Configuration::Configuration(const Configuration& other)
		:m_singleHostAddress(other.m_singleHostAddress)
		,m_hostAddress(other.m_hostAddress)
		,m_port(other.m_port)
		,m_threadPoolSize(other.m_threadPoolSize)
		,m_corsConfiguration(std::make_unique<CORSConfiguration>(*other.m_corsConfiguration))
		,m_securityConfiguration(std::make_unique<SecurityConfiguration>(*other.m_securityConfiguration))
	{
	}

	Configuration::~Configuration() = default;

	bool Configuration::hasSingleHostAddress() const
	{
		return m_singleHostAddress;
	}

	std::string Configuration::getHostAddress() const
	{
		return m_hostAddress;
	}

	unsigned int Configuration::getPort() const
	{
		return m_port;
	}

	size_t Configuration::getThreadPoolSize() const
	{
		return m_threadPoolSize;
	}

	void Configuration::setSingleHostAddress(bool singleHostAddress)
	{
		m_singleHostAddress = singleHostAddress;
	}

	void Configuration::setHostAddress(const std::string& hostAddress)
	{
		m_hostAddress = hostAddress;
	}

	void Configuration::setPort(unsigned int port)
	{
		m_port = port;
	}

	void Configuration::setThreadPoolSize(size_t threadPoolSize)
	{
		m_threadPoolSize = threadPoolSize;
	}

	const CORSConfiguration& Configuration::getCORSConfiguration() const
	{
		return *m_corsConfiguration;
	}

	CORSConfiguration& Configuration::getCORSConfiguration()
	{
		return *m_corsConfiguration;
	}

	const SecurityConfiguration& Configuration::getSecurityConfiguration() const
	{
		return *m_securityConfiguration;
	}

	SecurityConfiguration& Configuration::getSecurityConfiguration()
	{
		return *m_securityConfiguration;
	}

	Configuration& Configuration::operator= (const Configuration& other)
	{
		m_singleHostAddress = other.m_singleHostAddress;
		m_hostAddress = other.m_hostAddress;
		m_port = other.m_port;
		m_threadPoolSize = other.m_threadPoolSize;
		*m_corsConfiguration = *other.m_corsConfiguration;
		*m_securityConfiguration = *other.m_securityConfiguration;

		return *this;
	}

}}
