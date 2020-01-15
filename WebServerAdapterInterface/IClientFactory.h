#pragma once

#include <memory>


namespace systelab { namespace web_server {

	class IClient;

	class IClientFactory
	{
	public:
		virtual ~IClientFactory() = default;

		virtual std::unique_ptr<IClient> buildHTTPClient(const std::string& serverAddress, unsigned int port) const = 0;
		virtual std::unique_ptr<IClient> buildHTTPSClient(const std::string& serverAddress, unsigned int port) const = 0;
	};

}}
