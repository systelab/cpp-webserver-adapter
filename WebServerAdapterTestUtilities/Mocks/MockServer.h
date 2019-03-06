#pragma once

#include "WebServerAdapterInterface/IServer.h"

#include "WebServerAdapterInterface/IWebService.h"
#include "WebServerAdapterInterface/Model/Configuration.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockServer : public IServer
	{
	public:
		MockServer();
		virtual ~MockServer();

		MOCK_METHOD1(setConfigurationProxy, void(Configuration*));
		void setConfiguration(std::unique_ptr<Configuration> configuration)
		{
			setConfigurationProxy(configuration.release());
		}

		MOCK_METHOD1(registerWebServiceProxy, void(IWebService*));
		void registerWebService(std::unique_ptr<IWebService> service)
		{
			registerWebServiceProxy(service.release());
		}

		MOCK_CONST_METHOD0(isRunning, bool());
		MOCK_METHOD0(start, void());
		MOCK_METHOD0(stop, void());
	};

}}}

