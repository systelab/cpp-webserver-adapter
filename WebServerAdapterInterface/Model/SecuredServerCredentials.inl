
namespace systelab { namespace web_server {

	SecuredServerCredentials::SecuredServerCredentials()
		:m_certificate("")
		,m_privateKey("")
		,m_dhParam("")
	{
	}

	SecuredServerCredentials::~SecuredServerCredentials() = default;

	std::string SecuredServerCredentials::getCertificate() const
	{
		return m_certificate;
	}

	std::string SecuredServerCredentials::getPrivateKey() const
	{
		return m_privateKey;
	}

	std::string SecuredServerCredentials::getDHParam() const
	{
		return m_dhParam;
	}

	void SecuredServerCredentials::setCertificate(const std::string& certificate)
	{
		m_certificate = certificate;
	}

	void SecuredServerCredentials::setPrivateKey(const std::string& privateKey)
	{
		m_privateKey = privateKey;
	}

	void SecuredServerCredentials::setDHParam(const std::string& dhParam)
	{
		m_dhParam = dhParam;
	}

}}