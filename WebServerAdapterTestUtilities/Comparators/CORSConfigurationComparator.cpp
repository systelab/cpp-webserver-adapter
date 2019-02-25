#include "stdafx.h"
#include "TestUtilities/EntityComparator.h"

#include "Webserver/CORSConfiguration.h"

using testing::AssertionResult;
using testing::AssertionFailure;
using testing::AssertionSuccess;

namespace snow { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const http::server::CORSConfiguration& expected, const http::server::CORSConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, isEnabled());

		std::set<std::string> expectedAllowedOrigins = expected.getAllowedOrigins();
		std::set<std::string> actualAllowedOrigins = actual.getAllowedOrigins();
		COMPARATOR_ASSERT_EQUAL(expectedAllowedOrigins, actualAllowedOrigins, size());

		for (auto it = expectedAllowedOrigins.begin(); it != expectedAllowedOrigins.end(); it++)
		{
			std::string expectedAllowedOrigin = *it;
			if (actualAllowedOrigins.count(expectedAllowedOrigin) == 0)
			{
				return AssertionFailure() << "Expected allowed origin '" << expectedAllowedOrigin << "' not found";
			}
		}

		std::set<std::string> expectedExposedHeaders = expected.getExposedHeaders();
		std::set<std::string> actualExposedHeaders = actual.getExposedHeaders();
		COMPARATOR_ASSERT_EQUAL(expectedExposedHeaders, actualExposedHeaders, size());

		for (auto it = expectedExposedHeaders.begin(); it != expectedExposedHeaders.end(); it++)
		{
			std::string expectedExposedHeader = *it;
			if (actualExposedHeaders.count(expectedExposedHeader) == 0)
			{
				return AssertionFailure() << "Expected exposed header '" << expectedExposedHeader << "' not found";
			}
		}

		return AssertionSuccess();
	}

}}