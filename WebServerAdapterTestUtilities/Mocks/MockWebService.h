#pragma once

#include "WebServer/IWebService.h"
#include "WebServer/Request.h"
#include "WebServer/Reply.h"


namespace http { namespace server { namespace test_utility {

	class MockWebService : public IWebService
	{
	public:
		MockWebService() {};
		virtual ~MockWebService() {};

		MOCK_CONST_METHOD0(getPath, std::string());
	
		MOCK_CONST_METHOD1(buildProxy, Reply*(const Request&));
		std::unique_ptr<Reply> build(const Request& request) const
		{
			return std::unique_ptr<Reply>(buildProxy(request));
		}
	};

}}}

