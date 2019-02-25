#include "stdafx.h"
#include "TestUtilitiesInterface/EntityComparator.h"

#include "WebServerAdapterInterface/Model/CORSConfiguration.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::CORSConfiguration& expected, const systelab::web_server::CORSConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, isEnabled());

		// Allowed origins
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

		// Allowed methods
		std::set<std::string> expectedAllowedMethods = expected.getAllowedMethods();
		std::set<std::string> actualAllowedMethods = actual.getAllowedMethods();
		COMPARATOR_ASSERT_EQUAL(expectedAllowedMethods, actualAllowedMethods, size());

		for (auto it = expectedAllowedMethods.begin(); it != expectedAllowedMethods.end(); it++)
		{
			std::string expectedAllowedMethod = *it;
			if (actualAllowedMethods.count(expectedAllowedMethod) == 0)
			{
				return AssertionFailure() << "Expected allowed method '" << expectedAllowedMethod << "' not found";
			}
		}

		// Allowed headers
		std::set<std::string> expectedAllowedHeaders = expected.getAllowedHeaders();
		std::set<std::string> actualAllowedHeaders = actual.getAllowedHeaders();
		COMPARATOR_ASSERT_EQUAL(expectedAllowedHeaders, actualAllowedHeaders, size());

		for (auto it = expectedAllowedHeaders.begin(); it != expectedAllowedHeaders.end(); it++)
		{
			std::string expectedAllowedHeader = *it;
			if (actualAllowedHeaders.count(expectedAllowedHeader) == 0)
			{
				return AssertionFailure() << "Expected allowed header '" << expectedAllowedHeader << "' not found";
			}
		}

		// Exposed headers
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

		COMPARATOR_ASSERT_EQUAL(expected, actual, areAllowedCredentials());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getMaxAge());

		return AssertionSuccess();
	}

}}