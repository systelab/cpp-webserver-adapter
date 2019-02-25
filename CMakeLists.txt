cmake_minimum_required(VERSION 3.2)

macro(configure_test_utilities)
	# Configure repository to clone
	set(TEST_UTILITIES_URL https://github.com/systelab/cpp-test-utilities.git)	
	set(TEST_UTILITIES_DIR extern/TestUtilities)
	set(TEST_UTILITIES_BRANCH master)

	# Check if git is available
	find_package(Git)
	if(NOT GIT_FOUND)
		message(FATAL_ERROR "git not found!")
	endif()

	# Clone the test utilities repository
	if(EXISTS ${CMAKE_SOURCE_DIR}/${TEST_UTILITIES_DIR})
		message(STATUS "${TEST_UTILITIES_DIR} found, pulling...")
		execute_process(
                COMMAND             ${GIT_EXECUTABLE} pull origin master
                COMMAND             ${GIT_EXECUTABLE} submodule update --remote
                WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
                OUTPUT_VARIABLE     git_output)
	else()
		message(STATUS "${TEST_UTILITIES_DIR} directory not found, cloning...")
		execute_process(
				COMMAND             ${GIT_EXECUTABLE} clone ${TEST_UTILITIES_URL} ${TEST_UTILITIES_DIR}
				WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
				OUTPUT_VARIABLE     git_output)
	endif()
	
	# Checkout the right branch
	message(STATUS "Checking out ${TEST_UTILITIES_BRANCH} branch...")
	execute_process(
			COMMAND             ${GIT_EXECUTABLE} checkout ${TEST_UTILITIES_BRANCH}
			WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
			OUTPUT_VARIABLE     git_output)
			
	# Add cloned folder into includes
	include_directories(${CMAKE_SOURCE_DIR}/${TEST_UTILITIES_DIR})	
endmacro()


# Configure project
project(WebServerAdapter)

# Setup 3rd party libraries through conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()	

# Setup extern repositories
configure_test_utilities()

# Configure include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add subprojects
add_subdirectory(${CMAKE_SOURCE_DIR}/WebServerAdapterTestUtilities)

