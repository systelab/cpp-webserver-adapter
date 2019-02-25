cmake_minimum_required(VERSION 3.2)

# Add project folder into includes
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure DB Adapter test utilities project
set(WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT WebServerAdapterTestUtilities)
file(GLOB_RECURSE WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_SRC "*.cpp")
file(GLOB_RECURSE WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_HDR "*.h")
add_library(${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT} STATIC ${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
target_link_libraries(${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT} gmock_main)

# Configure source groups
foreach(FILE ${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${WEB_SERVER_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()
