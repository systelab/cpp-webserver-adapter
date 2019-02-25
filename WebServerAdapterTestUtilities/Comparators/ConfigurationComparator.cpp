#include "stdafx.h"
#include "WebServerAdapterInterface/Model/Configuration.h"

#include "TestUtilitiesInterface/EntityComparator.h"


using namespace testing;

namespace systelab { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const systelab::web_server::Configuration& expected, const systelab::web_server::Configuration& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, getHostAddress());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getPort());
		COMPARATOR_ASSERT_EQUAL(expected, actual, getThreadPoolSize());

		const systelab::web_server::CORSConfiguration& expectedCORSConfiguration = expected.getCORSConfiguration();
		const systelab::web_server::CORSConfiguration& actualCORSConfiguration = actual.getCORSConfiguration();
		AssertionResult corsConfigurationResult = EntityComparator()(expectedCORSConfiguration, actualCORSConfiguration);
		if (!corsConfigurationResult)
		{
			return AssertionFailure() << "Different CORS configuration: " << corsConfigurationResult.message();
		}

		return AssertionSuccess();
	}

}}
