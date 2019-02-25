#include "stdafx.h"
#include "WebServerAdapterInterface/Model/SecuredServerCredentials.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::SecuredServerCredentials& expected, const systelab::web_server::SecuredServerCredentials& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getCertificate());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPrivateKey());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getDHParam());

		return AssertionSuccess();
	}
}}