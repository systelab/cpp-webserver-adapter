#pragma once

namespace systelab { namespace web_server {

	class SecuredServerCredentials
	{
	public:
		inline SecuredServerCredentials();
		inline virtual ~SecuredServerCredentials();

		inline std::string getCertificate() const;
		inline std::string getPrivateKey() const;
		inline std::string getDHParam() const;

		inline void setCertificate(const std::string&);
		inline void setPrivateKey(const std::string&);
		inline void setDHParam(const std::string&);

	private:
		std::string m_certificate;
		std::string m_privateKey;
		std::string m_dhParam;
	};

}}

#include "SecuredServerCredentials.inl"

