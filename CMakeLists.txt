cmake_minimum_required(VERSION 3.2)

project(WebServerAdapter)

# Configure environment
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup 3rd party libraries through conan
include(Conan)
conan_cmake_run(REQUIRES boost/1.67.0@conan/stable
                         OpenSSL/1.0.2n@conan/stable
                         gtest/1.8.1@bincrafters/stable
                BASIC_SETUP
                BUILD missing)

# Setup extern repositories
include(GitCloneRepository)
git_clone_repository(URL https://github.com/systelab/cpp-test-utilities.git DIR extern/TestUtilities BRANCH master)

# Configure include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add subprojects
add_subdirectory(${CMAKE_SOURCE_DIR}/WebServerAdapterTestUtilities)
