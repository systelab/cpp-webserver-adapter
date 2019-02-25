#pragma once

#include "WebServer/CORSConfiguration.h"
#include "WebServer/IListener.h"
#include "WebServer/ISecuredServer.h"
#include "WebServer/IWebService.h"


namespace http { namespace server { namespace test_utility {

	class MockSecuredServer : public ISecuredServer
	{
	public:
		MockSecuredServer() {};
		virtual ~MockSecuredServer() {};

		MOCK_METHOD0(run, void());
		MOCK_METHOD0(stop, void());

		MOCK_METHOD1(registerServiceProxy, void(IWebService*));
		void registerService(std::unique_ptr<IWebService> webService)
		{
			registerServiceProxy(webService.release());
		}

		MOCK_METHOD1(registerListenerProxy, void(IListener*));
		void registerListener(std::unique_ptr<IListener> listener)
		{
			registerListenerProxy(listener.release());
		}

		MOCK_METHOD1(setCORSConfigurationProxy, void(CORSConfiguration*));
		void setCORSConfiguration(std::unique_ptr<CORSConfiguration> configuration)
		{
			setCORSConfigurationProxy(configuration.release());
		}

		MOCK_METHOD1(setServerCredentials, void(const Credentials&));
		MOCK_METHOD1(setClientCredentials, void(const Credentials&));
	};

}}}

