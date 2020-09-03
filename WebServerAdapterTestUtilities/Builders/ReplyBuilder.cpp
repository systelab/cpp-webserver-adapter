#include "ReplyBuilder.h"


namespace systelab { namespace web_server { namespace test_utility {

	ReplyBuilder::ReplyBuilder()
		:m_reply()
	{
	}

	ReplyBuilder::~ReplyBuilder() = default;


	ReplyBuilder& ReplyBuilder::setStatus(Reply::StatusType status)
	{
		m_reply.setStatus(status);
		return *this;
	}

	ReplyBuilder& ReplyBuilder::addHeader(const std::string& header, const std::string& value)
	{
		m_reply.addHeader(header, value);
		return *this;
	}

	ReplyBuilder& ReplyBuilder::setContent(const std::string& content)
	{
		m_reply.setContent(content);
		return *this;
	}

	Reply ReplyBuilder::getEntity() const
	{
		return m_reply;
	}

}}}
