cmake_minimum_required(VERSION 3.2)

project(WebServerAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Setup up Google test
include(ConfigureGoogleTest)
configure_google_test()

# Find external dependencies
find_package(WebServerAdapter)

# Configure test package project
set(WEB_SERVER_ADAPTER_PACKAGE_TEST_PROJECT WebServerAdapterPackageTest)
add_executable(${WEB_SERVER_ADAPTER_PACKAGE_TEST_PROJECT} WebServerAdapterExample.cpp)
target_link_libraries(${WEB_SERVER_ADAPTER_PACKAGE_TEST_PROJECT} WebServerAdapter::WebServerAdapter gmock_main)

# Register tests
enable_testing()
add_test(NAME WebServerAdapterPackageTest COMMAND ${WEB_SERVER_ADAPTER_PACKAGE_TEST_PROJECT})
