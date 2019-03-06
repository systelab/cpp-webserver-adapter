#pragma once

#include "WebServerAdapterInterface/IWebService.h"

#include "WebServerAdapterInterface/Model/Reply.h"
#include "WebServerAdapterInterface/Model/Request.h"


namespace systelab { namespace web_server { namespace test_utility {

	class MockWebService : public IWebService
	{
	public:
		MockWebService();
		virtual ~MockWebService();

		MOCK_CONST_METHOD1(processProxy, Reply*(const Request&));
		std::unique_ptr<Reply> process(const Request& request) const
		{
			return std::unique_ptr<Reply>(processProxy(request));
		}
	};

}}}

