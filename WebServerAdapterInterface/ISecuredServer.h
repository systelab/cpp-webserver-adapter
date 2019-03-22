#pragma once

#include "IServer.h"

namespace systelab { namespace web_server {

	class CORSConfiguration;
	class IWebService;
	class SecuredServerCredentials;

	class ISecuredServer : public IServer
	{
	public:
		virtual ~ISecuredServer() = default;

		virtual void setServerCredentials(std::unique_ptr<SecuredServerCredentials>) = 0;
		virtual void setClientCredentials(const std::string&) = 0;
	};

}}