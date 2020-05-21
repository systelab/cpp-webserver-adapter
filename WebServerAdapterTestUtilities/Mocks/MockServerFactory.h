#pragma once

#include "WebServerAdapterInterface/IServerFactory.h"

#include "WebServerAdapterInterface/IServer.h"
#include "WebServerAdapterInterface/Model/Configuration.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockServerFactory : public IServerFactory
	{
	public:
		MockServerFactory();
		virtual ~MockServerFactory();

		MOCK_CONST_METHOD1(buildServerProxy, IServer*(const Configuration&));
		std::unique_ptr<IServer> buildServer(const Configuration& configuration) const override
		{
			return std::unique_ptr<IServer>(buildServerProxy(configuration));
		}
	};

}}}

