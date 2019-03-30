#include "stdafx.h"
#include "WebServerAdapterInterface/Model/RequestQueryStrings.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::RequestQueryStrings& expected, const systelab::web_server::RequestQueryStrings& actual) const
	{
		auto expectedQueryStrings = expected.getItemsMap();
		auto actualQueryStrings = actual.getItemsMap();

		COMPARATOR_ASSERT_EQUAL(expectedQueryStrings, actualQueryStrings, size() );
		for (auto it = expectedQueryStrings.begin(); it != expectedQueryStrings.end(); it++)
		{
			std::string expectedQueryStringName = it->first;
			std::string expectedQueryStringValue = it->second;

			if (actualQueryStrings.find(expectedQueryStringName) == actualQueryStrings.end())
			{
				return AssertionFailure() << "Expected query string '" << expectedQueryStringName << "' not found";
			}

			if (actualQueryStrings[expectedQueryStringName] != expectedQueryStringValue)
			{
				return AssertionFailure() << "Query string '" << expectedQueryStringName << "' is different: expected="
										  << expectedQueryStringValue << ", actual= " << actualQueryStrings[expectedQueryStringName];
			}
		}

		return AssertionSuccess();
	}

}}
