#include "StdAfx.h"
#include "StubService.h"

#include "WebServerAdapterInterface/Model/Reply.h"
#include "WebServerAdapterInterface/Model/Request.h"


namespace systelab { namespace web_server { namespace test_utility {

	StubService::StubService(const systelab::web_server::Reply& defaultReply)
		:m_defaultReply(defaultReply)
	{
	}

	StubService::~StubService() = default;

	std::unique_ptr<systelab::web_server::Reply> StubService::build(const systelab::web_server::Request&) const
	{
		auto reply = std::make_unique<systelab::web_server::Reply>(m_defaultReply);
		reply->addHeader("Content-Length", std::to_string(m_defaultReply.getContent().size()));
		reply->addHeader("Content-Type", "text/html");

		return std::move(reply);
	}

}}}
