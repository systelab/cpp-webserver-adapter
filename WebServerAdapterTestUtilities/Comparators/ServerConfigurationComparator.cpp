#include "stdafx.h"
#include "TestUtilities/EntityComparator.h"

#include "Webserver/ServerConfiguration.h"


using testing::AssertionResult;
using testing::AssertionFailure;
using testing::AssertionSuccess;

namespace snow { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const http::server::ServerConfiguration& expected, const http::server::ServerConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getAddress());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPort());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getThreadPoolSize());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getLogChannel());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getLCID());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isPreventFloodEnabled());

		return AssertionSuccess();
	}

}}
