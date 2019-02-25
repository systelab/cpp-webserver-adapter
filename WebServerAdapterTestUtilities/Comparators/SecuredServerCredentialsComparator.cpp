#include "stdafx.h"
#include "TestUtilities/EntityComparator.h"

#include "Webserver/ISecuredServer.h"

using testing::AssertionResult;
using testing::AssertionFailure;
using testing::AssertionSuccess;

namespace snow { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const http::server::ISecuredServer::Credentials& expected, const http::server::ISecuredServer::Credentials& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, certificate);
		COMPARATOR_ASSERT_EQUAL(expected, actual, privateKey);
		COMPARATOR_ASSERT_EQUAL(expected, actual, dhParam);

		return AssertionSuccess();
	}
}}