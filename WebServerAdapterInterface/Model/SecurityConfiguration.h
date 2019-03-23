#pragma once

namespace systelab { namespace web_server {

	class SecurityConfiguration
	{
	public:
		inline SecurityConfiguration();
		inline SecurityConfiguration(const SecurityConfiguration&);
		inline virtual ~SecurityConfiguration();

		inline bool isHTTPSEnabled() const;
		inline std::string getServerCertificate() const;
		inline std::string getServerPrivateKey() const;
		inline std::string getServerDHParam() const;

		inline bool isMutualSSLEnabled() const;
		inline std::string getClientCertificate() const;

		inline void setHTTPSEnabled(bool);
		inline void setServerCertificate(const std::string&);
		inline void setServerPrivateKey(const std::string&);
		inline void setServerDHParam(const std::string&);

		inline void setMutualSSLEnabled(bool);
		inline void setClientCertificate(const std::string&);

		inline SecurityConfiguration& operator= (const SecurityConfiguration&);

	private:
		bool m_httpsEnabled;
		std::string m_serverCertificate;
		std::string m_serverPrivateKey;
		std::string m_serverDHParam;

		bool m_mutualSSLEnabled;
		std::string m_clientCertificate;
	};

}}

#include "SecurityConfiguration.inl"

