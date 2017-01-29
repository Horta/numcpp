cmake_minimum_required (VERSION 3.2.2)

file(STRINGS "VERSION" NUMCPP_VERSION)

project(NumCpp VERSION ${NUMCPP_VERSION} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)
add_subdirectory(numcpp)

add_library(numcpp INTERFACE)
target_include_directories(numcpp INTERFACE
  $<INSTALL_INTERFACE:numcpp/numcpp.hpp>
)
install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/numcpp/numcpp.hpp
  DESTINATION include
)

add_subdirectory(test)

enable_testing()
add_test(NAME TestLinking COMMAND test_linking)
