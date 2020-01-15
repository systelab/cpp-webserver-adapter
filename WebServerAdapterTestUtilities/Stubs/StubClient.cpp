#include "stdafx.h"
#include "StubClient.h"


namespace systelab { namespace web_server { namespace test_utility {

	StubClient::StubClient(const systelab::web_server::Reply& defaultReply)
		:m_defaultReply(defaultReply)
	{
		ON_CALL(*this, sendProxy(testing::_)).WillByDefault(testing::Invoke(
			[this](const Request&) -> Reply*
			{
				return std::make_unique<Reply>(m_defaultReply).release();
			}
		));
	}

	StubClient::~StubClient() = default;

	void StubClient::setReply(const Reply& newDefaultReply)
	{
		m_defaultReply = newDefaultReply;
	}

}}}
