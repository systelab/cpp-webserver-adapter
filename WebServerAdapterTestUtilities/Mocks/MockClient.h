#pragma once

#include "WebServerAdapterInterface/IClient.h"
#include "WebServerAdapterInterface/Model/Reply.h"
#include "WebServerAdapterInterface/Model/Request.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockClient : public IClient
	{
	public:
		MockClient();
		virtual ~MockClient();

		MOCK_CONST_METHOD1(sendProxy, Reply*(const Request&));
		std::unique_ptr<Reply> send(const Request& request) const override
		{
			return std::unique_ptr<Reply>(sendProxy(request));
		}
	};

}}}

