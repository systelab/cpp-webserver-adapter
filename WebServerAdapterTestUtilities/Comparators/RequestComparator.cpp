#include "stdafx.h"
#include "WebServerAdapterInterface/Model/Request.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::Request& expected, const systelab::web_server::Request& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getMethod());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getURI());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getURIFull());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHttpVersionMajor());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHttpVersionMinor());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getContent());

		const auto& expectedHeaders = expected.getHeaders();
		const auto& actualHeaders = actual.getHeaders();
		AssertionResult headersResult = EntityComparator()(expectedHeaders, actualHeaders);
		if (!headersResult)
		{
			return AssertionFailure() << "Different headers: " << headersResult.message();
		}

		const auto& expectedQueryStrings = expected.getQueryStrings();
		const auto& actualQueryStrings = actual.getQueryStrings();
		AssertionResult queryStringsResult = EntityComparator()(expectedQueryStrings, actualQueryStrings);
		if (!queryStringsResult)
		{
			return AssertionFailure() << "Different query strings: " << queryStringsResult.message();
		}

		return AssertionSuccess();
	}

}}
