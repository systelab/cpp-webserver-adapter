#include "CORSConfiguration.h"


namespace systelab { namespace web_server {

	Configuration::Configuration(const std::string& hostAddress,
								 unsigned int port,
								 unsigned int threadPoolSize)
		:m_hostAddress(hostAddress)
		,m_port(port)
		,m_threadPoolSize(threadPoolSize)
		,m_corsConfiguration(new CORSConfiguration())
	{
	}

	Configuration::Configuration(const Configuration& other)
		:m_hostAddress(other.m_hostAddress)
		,m_port(other.m_port)
		,m_threadPoolSize(other.m_threadPoolSize)
		,m_corsConfiguration(new CORSConfiguration(*other.m_corsConfiguration))
	{
	}

	Configuration::~Configuration()
	{
	}

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

	Configuration& Configuration::operator= (const Configuration& other)
	{
		m_hostAddress = other.m_hostAddress;
		m_port = other.m_port;
		m_threadPoolSize = other.m_threadPoolSize;
		*m_corsConfiguration = *other.m_corsConfiguration;

		return *this;
	}

}}
