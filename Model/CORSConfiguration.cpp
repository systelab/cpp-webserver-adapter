#include "StdAfx.h"
#include "CORSConfiguration.h"


namespace systelab { namespace web_server {

	CORSConfiguration::CORSConfiguration()
		:m_enabled(false)
		,m_allowedOrigins()
	{
	}

	CORSConfiguration::CORSConfiguration(const CORSConfiguration& other)
		:m_enabled(other.m_enabled)
		,m_allowedOrigins(other.m_allowedOrigins)
	{
	}

	CORSConfiguration::~CORSConfiguration()
	{
	}

	bool CORSConfiguration::isEnabled() const
	{
		return m_enabled;
	}

	void CORSConfiguration::setEnabled(bool enabled)
	{
		m_enabled = enabled;
	}

	bool CORSConfiguration::isAllowedOrigin(const std::string& allowedOrigin) const
	{
		return (m_allowedOrigins.count(allowedOrigin) > 0);
	}

	void CORSConfiguration::addAllowedOrigin(const std::string& allowedOrigin)
	{
		m_allowedOrigins.insert(allowedOrigin);
	}

	CORSConfiguration& CORSConfiguration::operator= (const CORSConfiguration& other)
	{
		m_enabled = other.m_enabled;
		m_allowedOrigins = other.m_allowedOrigins;

		return *this;
	}

}}
