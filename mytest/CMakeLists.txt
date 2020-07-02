
cmake_minimum_required(VERSION 2.8.10)

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
include_directories(.)

set(RestbedSRCS ${MANIFEST})

#
# GET
#
add_executable(getclient getclient.cpp ${RestbedSRCS})
add_executable(getserver getserver.cpp ${RestbedSRCS})

#
# POST
#
add_executable(postclient postclient.cpp ${RestbedSRCS})
add_executable(postserver postserver.cpp ${RestbedSRCS})

#
# efficiency of POST method
#
add_executable(efficlient efficlient.cpp ${RestbedSRCS})
add_executable(effiserver effiserver.cpp ${RestbedSRCS})

#
# multiple request
#
add_executable(multiclient multiclient.cpp ${RestbedSRCS})
add_executable(multiserver multiserver.cpp ${RestbedSRCS})

#
# thread server
#
add_executable(threadclient threadclient.cpp ${RestbedSRCS})
add_executable(threadserver threadserver.cpp ${RestbedSRCS})