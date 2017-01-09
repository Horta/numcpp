cmake_minimum_required (VERSION 3.2.2)

project(NumCpp CPP)

set(CMAKE_CPP_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

file(STRINGS "VERSION" NUMCPP_VERSION)

include_directories(.)

add_subdirectory(numcpp)

set_target_properties(numcpp
  PROPERTIES
    VERSION ${NUMCPP_VERSION}
  PUBLIC_HEADER "numcpp/numcpp.h")

install(TARGETS numcpp
        PUBLIC_HEADER DESTINATION include/numcpp)

add_subdirectory(test)

enable_testing()
add_test(NAME TestLinking COMMAND test_linking)
