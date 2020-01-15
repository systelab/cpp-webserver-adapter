#pragma once

#include "WebServerAdapterInterface/IClientFactory.h"

#include "WebServerAdapterInterface/IClient.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockClientFactory : public IClientFactory
	{
	public:
		MockClientFactory();
		virtual ~MockClientFactory();

		MOCK_CONST_METHOD2(buildHTTPClientProxy, IClient*(const std::string&, unsigned int));
		std::unique_ptr<IClient> buildHTTPClient(const std::string& serverAddress, unsigned int port) const override
		{
			return std::unique_ptr<IClient>(buildHTTPClientProxy(serverAddress, port));
		}

		MOCK_CONST_METHOD2(buildHTTPSClientProxy, IClient*(const std::string&, unsigned int));
		std::unique_ptr<IClient> buildHTTPSClient(const std::string& serverAddress, unsigned int port) const override
		{
			return std::unique_ptr<IClient>(buildHTTPSClientProxy(serverAddress, port));
		}
	};

}}}

