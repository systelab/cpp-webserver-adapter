#pragma once

#include "../Mocks/MockClient.h"


namespace systelab { namespace web_server { namespace test_utility {

	class StubClient : public MockClient
	{
	public:
		StubClient(const Reply& defaultReply);
		virtual ~StubClient();

		void setReply(const Reply& newDefaultReply);

	private:
		Reply m_defaultReply;
	};

}}}
