#pragma once

#include "WebServerAdapterInterface/IWebService.h"


namespace systelab { namespace web_server { namespace test_utility {

	class StubWebService : public IWebService
	{
	public:
		StubWebService(const Reply& defaultReply);
		virtual ~StubWebService();

		std::unique_ptr<Reply> build(const Request&) const;

	private:
		const Reply& m_defaultReply;
	};

}}}
