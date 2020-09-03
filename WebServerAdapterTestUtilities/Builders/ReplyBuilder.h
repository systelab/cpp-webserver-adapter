#pragma once

#include "WebServerAdapterInterface/Model/Reply.h"


namespace systelab { namespace web_server { namespace test_utility {

	class ReplyBuilder
	{
	public:
		ReplyBuilder();
		virtual ~ReplyBuilder();

		ReplyBuilder& setStatus(Reply::StatusType);
		ReplyBuilder& addHeader(const std::string& header, const std::string& value);
		ReplyBuilder& setContent(const std::string&);

		Reply getEntity() const;

	private:
		Reply m_reply;
	};

}}}

