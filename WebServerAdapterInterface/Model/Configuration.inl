#include "CORSConfiguration.h"
#include "SecurityConfiguration.h"


namespace systelab { namespace web_server {

	Configuration::Configuration(const std::string& hostAddress,
								 unsigned int port,
								 unsigned int threadPoolSize)
		:m_hostAddress(hostAddress)
		,m_port(port)
		,m_threadPoolSize(threadPoolSize)
		,m_corsConfiguration(std::make_unique<CORSConfiguration>())
		,m_securityConfiguration(std::make_unique<SecurityConfiguration>())
	{
	}

	Configuration::Configuration(const Configuration& other)
		:m_hostAddress(other.m_hostAddress)
		,m_port(other.m_port)
		,m_threadPoolSize(other.m_threadPoolSize)
		,m_corsConfiguration(std::make_unique<CORSConfiguration>(*other.m_corsConfiguration))
		,m_securityConfiguration(std::make_unique<SecurityConfiguration>(*other.m_securityConfiguration))
	{
	}

	Configuration::~Configuration() = default;

	std::string Configuration::getHostAddress() const
	{
		return m_hostAddress;
	}

	unsigned int Configuration::getPort() const
	{
		return m_port;
	}

	unsigned int Configuration::getThreadPoolSize() const
	{
		return m_threadPoolSize;
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
		m_hostAddress = other.m_hostAddress;
		m_port = other.m_port;
		m_threadPoolSize = other.m_threadPoolSize;
		*m_corsConfiguration = *other.m_corsConfiguration;
		*m_securityConfiguration = *other.m_securityConfiguration;

		return *this;
	}

}}
