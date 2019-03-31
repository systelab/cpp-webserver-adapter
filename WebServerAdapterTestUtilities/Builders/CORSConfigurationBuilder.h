#pragma once

#include "WebServerAdapterInterface/Model/CORSConfiguration.h"


namespace systelab { namespace web_server { namespace test_utility {

	class CORSConfigurationBuilder
	{
	public:
		CORSConfigurationBuilder();
		virtual ~CORSConfigurationBuilder();

		CORSConfigurationBuilder& setEnabled(bool);

		CORSConfigurationBuilder& addAllowedOrigin(const std::string&);
		CORSConfigurationBuilder& addAllowedMethod(const std::string&);
		CORSConfigurationBuilder& addAllowedHeader(const std::string&);
		CORSConfigurationBuilder& addExposedHeader(const std::string&);

		CORSConfigurationBuilder& setAllowedCredentials(bool);
		CORSConfigurationBuilder& setMaxAge(unsigned int);

		CORSConfiguration getEntity() const;

	private:
		CORSConfiguration m_CORSConfiguration;
	};

}}}

