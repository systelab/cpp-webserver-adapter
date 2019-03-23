#pragma once

#include "WebServerAdapterInterface/IServerFactory.h"

#include "WebServerAdapterInterface/Model/Configuration.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockServerFactory : public IServerFactory
	{
	public:
		MockServerFactory();
		virtual ~MockServerFactory();

		MOCK_METHOD1(setConfigurationProxy, void(Configuration*));
		void setConfiguration(std::unique_ptr<Configuration> configuration)
		{
			setConfigurationProxy(configuration.release());
		}
	};

}}}

