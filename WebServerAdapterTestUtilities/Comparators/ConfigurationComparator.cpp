#include "stdafx.h"
#include "WebServerAdapterInterface/Model/Configuration.h"

#include "TestUtilitiesInterface/EntityComparator.h"
#include "TestUtilitiesInterface/EntityComparatorMacros.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::Configuration& expected, const systelab::web_server::Configuration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, hasSingleHostAddress());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHostAddress());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPort());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getThreadPoolSize());
		COMPARATOR_ASSERT_EQUAL(expected, actual, isGZIPCompressionEnabled());

		const auto& expectedCORSConfiguration = expected.getCORSConfiguration();
		const auto& actualCORSConfiguration = actual.getCORSConfiguration();
		AssertionResult corsConfigurationResult = EntityComparator()(expectedCORSConfiguration, actualCORSConfiguration);
		if (!corsConfigurationResult)
		{
			return AssertionFailure() << "Different CORS configuration: " << corsConfigurationResult.message();
		}

		const auto& expectedSecurityConfiguration = expected.getSecurityConfiguration();
		const auto& actualSecurityConfiguration = actual.getSecurityConfiguration();
		AssertionResult securityConfigurationResult = EntityComparator()(expectedSecurityConfiguration, actualSecurityConfiguration);
		if (!securityConfigurationResult)
		{
			return AssertionFailure() << "Different security configuration: " << securityConfigurationResult.message();
		}

		return AssertionSuccess();
	}

}}
