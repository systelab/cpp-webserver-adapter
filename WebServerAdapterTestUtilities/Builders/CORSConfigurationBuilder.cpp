#include "CORSConfigurationBuilder.h"

namespace systelab { namespace web_server { namespace test_utility {

	CORSConfigurationBuilder::CORSConfigurationBuilder()
		:m_CORSConfiguration()
	{
	}

	CORSConfigurationBuilder::~CORSConfigurationBuilder() = default;

	CORSConfigurationBuilder& CORSConfigurationBuilder::setEnabled(bool enabled)
	{
		m_CORSConfiguration.setEnabled(enabled);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::addAllowedOrigin(const std::string& allowedOrigin)
	{
		m_CORSConfiguration.addAllowedOrigin(allowedOrigin);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::addAllowedMethod(const std::string& allowedMethod)
	{
		m_CORSConfiguration.addAllowedMethod(allowedMethod);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::addAllowedHeader(const std::string& allowedHeader)
	{
		m_CORSConfiguration.addAllowedHeader(allowedHeader);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::addExposedHeader(const std::string& exposedHeader)
	{
		m_CORSConfiguration.addExposedHeader(exposedHeader);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::setAllowedCredentials(bool allowedCredentials)
	{
		m_CORSConfiguration.setAllowedCredentials(allowedCredentials);
		return *this;
	}

	CORSConfigurationBuilder& CORSConfigurationBuilder::setMaxAge(unsigned int maxAge)
	{
		m_CORSConfiguration.setMaxAge(maxAge);
		return *this;
	}

	CORSConfiguration CORSConfigurationBuilder::getEntity() const
	{
		return m_CORSConfiguration;
	}

}}}
