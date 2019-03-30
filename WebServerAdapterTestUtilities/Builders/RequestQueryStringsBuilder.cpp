#include "RequestQueryStringsBuilder.h"

namespace systelab { namespace web_server { namespace test_utility {

	RequestQueryStringsBuilder::RequestQueryStringsBuilder()
		:m_requestQueryStrings()
	{
	}

	RequestQueryStringsBuilder::~RequestQueryStringsBuilder() = default;

	RequestQueryStringsBuilder& RequestQueryStringsBuilder::addItem(const std::string& name, const std::string& value)
	{
		m_requestQueryStrings.addItem(name, value);
		return *this;
	}

	RequestQueryStrings RequestQueryStringsBuilder::getEntity() const
	{
		return m_requestQueryStrings;
	}

}}}