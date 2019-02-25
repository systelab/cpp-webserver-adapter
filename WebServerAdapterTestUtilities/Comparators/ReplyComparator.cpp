#include "stdafx.h"
#include "WebServerAdapterInterface/Model/Reply.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::Reply& expected, const systelab::web_server::Reply& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getContent());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getStatus());

		std::map<std::string, std::string> expectedHeaders = expected.getHeaders();
		std::map<std::string, std::string> actualHeaders = actual.getHeaders();

		COMPARATOR_ASSERT_EQUAL(expectedHeaders, actualHeaders, size() );
		for (auto it = expectedHeaders.begin(); it != expectedHeaders.end(); it++)
		{
			std::string expectedHeaderName = it->first;
			std::string expectedHeaderValue = it->second;

			if (actualHeaders.find(expectedHeaderName) == actualHeaders.end())
			{
				return AssertionFailure() << "Expected header '" << expectedHeaderName << "' not found";
			}

			if (actualHeaders[expectedHeaderName] != expectedHeaderValue)
			{
				return AssertionFailure() << "Header '" << expectedHeaderName << "' is different: expected="
										  << expectedHeaderValue << ", actual= " << actualHeaders[expectedHeaderName];
			}

		}

		return AssertionSuccess();
	}

}}
