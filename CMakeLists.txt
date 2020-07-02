# Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
cmake_minimum_required( VERSION 2.8.10 )

project( restbed CXX )
set( restbed_VERSION_MAJOR 4 )
set( restbed_VERSION_MINOR 6.0 )
set( restbed_VERSION ${restbed_VERSION_MAJOR}.${restbed_VERSION_MINOR} )
set( PACKAGE_VERSION ${restbed_VERSION} )
set( VERSION "${restbed_VERSION}" )

add_subdirectory(mytest)
