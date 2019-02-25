#pragma once

namespace systelab { namespace web_server {

	class SecuredServerCredentials
	{
	public:
		SecuredServerCredentials();
		virtual ~SecuredServerCredentials();

		std::string getCertificate() const;
		std::string getPrivateKey() const;
		std::string getDHParam() const;

		void setCertificate(const std::string&);
		void setPrivateKey(const std::string&);
		void setDHParam(const std::string&);

	private:
		std::string m_certificate;
		std::string m_privateKey;
		std::string m_dhParam;
	};

}}

#include "SecuredServerCredentials.inl"

