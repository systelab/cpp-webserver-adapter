#pragma once

#include <memory>
#include <string>


namespace systelab { namespace web_server {

	class CORSConfiguration;

	class Configuration
	{
	public:
		Configuration(const std::string& hostAddress,
					  unsigned int port,
					  unsigned int threadPoolSize);
		Configuration(const Configuration&);
		virtual ~Configuration();

		std::string getHostAddress() const;
		unsigned int getPort() const;
		unsigned int getThreadPoolSize() const;

		const CORSConfiguration& getCORSConfiguration() const;
		CORSConfiguration& getCORSConfiguration();

		Configuration& operator= (const Configuration& other);

	private:
		std::string m_hostAddress;
		unsigned int m_port;
		unsigned int m_threadPoolSize;
		std::unique_ptr<CORSConfiguration> m_corsConfiguration;
	};

}}
