#include "stdafx.h"
#include "WebServerAdapterInterface/Model/SecurityConfiguration.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::SecurityConfiguration& expected,
														   const systelab::web_server::SecurityConfiguration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, isHTTPSEnabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerCertificate());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerPrivateKey());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getServerDHParam());

		COMPARATOR_ASSERT_EQUAL(expected, actual, isMutualSSLEnabled());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getClientCertificate());

		return AssertionSuccess();
	}

}}
