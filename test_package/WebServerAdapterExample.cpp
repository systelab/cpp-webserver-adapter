#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "WebServerAdapterTestUtilities/Mocks/MockServer.h"


int main(int argc, char *argv[])
{
    systelab::web_server::test_utility::MockServer server;
    std::cout << "Web server adapter test utilities work as expected" << std::endl;

    return 0;
}
