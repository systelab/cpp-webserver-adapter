#include "stdafx.h"
#include "WebServerAdapterInterface/Model/RequestHeaders.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::RequestHeaders& expected, const systelab::web_server::RequestHeaders& actual) const
	{
		auto expectedHeaders = expected.getHeadersMap();
		auto actualHeaders = actual.getHeadersMap();

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
