#include "stdafx.h"
#include "EntityComparator.h"

#include "Webserver/Request.h"

using testing::AssertionResult;
using testing::AssertionFailure;
using testing::AssertionSuccess;

namespace http { namespace server { namespace test_utility {

	template <>
	testing::AssertionResult EntityComparator::operator() (const http::server::Request& expected, const http::server::Request& actual) const
	{
		COMPARATOR_ASSERT_EQUAL(expected, actual, method);
		COMPARATOR_ASSERT_EQUAL(expected, actual, uri);
		COMPARATOR_ASSERT_EQUAL(expected, actual, http_version_major);
		COMPARATOR_ASSERT_EQUAL(expected, actual, http_version_minor);
		COMPARATOR_ASSERT_EQUAL(expected, actual, contentLength);
		COMPARATOR_ASSERT_EQUAL(expected, actual, content);
		COMPARATOR_ASSERT_EQUAL(expected, actual, bad);

		std::map<std::string, std::string> expectedHeaders = expected.headers;
		std::map<std::string, std::string> actualHeaders = actual.headers;

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

}}}
