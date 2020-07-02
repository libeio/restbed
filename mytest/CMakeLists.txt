
cmake_minimum_required(VERSION 2.8.10)

project(restbed CXX)
set(restbed_VERSION_MAJOR 4)
set(restbed_VERSION_MINOR 6.0 )
set(restbed_VERSION ${restbed_VERSION_MAJOR}.${restbed_VERSION_MINOR})
set(PACKAGE_VERSION ${restbed_VERSION})
set(VERSION "${restbed_VERSION}")

message("PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})

string(REGEX REPLACE "/mytest$" "" PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR})

#
# Configuration
#
include("${PROJECT_SOURCE_DIR}/cmake/configuration.cmake")
#
# Dependencies
#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")

find_package(asio REQUIRED)
include_directories(SYSTEM ${asio_INCLUDE})

find_package(kashmir REQUIRED)
include_directories(SYSTEM ${kashmir_INCLUDE})

#
# Build
#
include("${PROJECT_SOURCE_DIR}/cmake/manifest.cmake")

include_directories(${INCLUDE_DIR})

set(RestbedSRCS ${MANIFEST})

add_executable(rfserver rfserver.cpp ${RestbedSRCS})
add_executable(rfclient rfclient.cpp ${RestbedSRCS})
