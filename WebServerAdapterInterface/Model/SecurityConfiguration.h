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

		inline bool isTLSv10Enabled() const;
		inline bool isTLSv11Enabled() const;
		inline bool isTLSv12Enabled() const;
		inline bool isTLSv13Enabled() const;

		inline void setHTTPSEnabled(bool);
		inline void setServerCertificate(const std::string&);
		inline void setServerPrivateKey(const std::string&);
		inline void setServerDHParam(const std::string&);

		inline void setMutualSSLEnabled(bool);
		inline void setClientCertificate(const std::string&);

		inline void setTLSv10Enabled(bool);
		inline void setTLSv12Enabled(bool);
		inline void setTLSv13Enabled(bool);
		inline void setTLSv11Enabled(bool);

		inline SecurityConfiguration& operator= (const SecurityConfiguration&);

	private:
		bool m_httpsEnabled;
		std::string m_serverCertificate;
		std::string m_serverPrivateKey;
		std::string m_serverDHParam;

		bool m_mutualSSLEnabled;
		std::string m_clientCertificate;
		
		bool m_tlsv10Enabled;
		bool m_tlsv11Enabled;
		bool m_tlsv12Enabled;
		bool m_tlsv13Enabled;
	};

}}

#include "SecurityConfiguration.inl"

