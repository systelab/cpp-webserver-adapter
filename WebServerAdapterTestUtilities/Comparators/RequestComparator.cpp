#include "stdafx.h"
#include "WebServerAdapterInterface/Model/Request.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::Request& expected, const systelab::web_server::Request& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getMethod());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getURI());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHttpVersionMajor());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHttpVersionMinor());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getContent());

		auto expectedHeaders = expected.getHeaders().getHeadersMap();
		auto actualHeaders = actual.getHeaders().getHeadersMap();

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
