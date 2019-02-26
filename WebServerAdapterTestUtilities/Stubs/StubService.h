#pragma once

#include "WebServerAdapterInterface/IService.h"


namespace systelab { namespace web_server { namespace test_utility {

	class StubService : public IService
	{
	public:
		StubService(const Reply& defaultReply);
		virtual ~StubService();

		std::unique_ptr<Reply> build(const Request&) const;

	private:
		const Reply& m_defaultReply;
	};

}}}
