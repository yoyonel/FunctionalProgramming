cmake_minimum_required(VERSION 3.2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# https://stackoverflow.com/questions/41361631/optimize-in-cmake-by-default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

if(CMAKE_BUILD_TYPE EQUAL "Release")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

project(FunctionalPlus_Examples VERSION 0.1.0)

message(STATUS "===( ${PROJECT_NAME} ${PROJECT_VERSION} ${CMAKE_BUILD_TYPE} )===")

find_package(FunctionalPlus REQUIRED)
add_library(FunctionalPlus INTERFACE)

#
add_executable(fplus_test src/fplus_test.cpp)
add_executable(Correctness_follows_by_expressiveness
    src/Correctness_follows_by_expressiveness.cpp
    )
add_executable(square_values src/square_values.cpp)

add_executable(Programming_challenge_parse_and_product
    src/Programming_challenge_parse_and_product.cpp
    src/Programming_challenge_parse_and_product.hpp)
include_directories(Programming_challenge_parse_and_product src/)

add_executable(lambdas_and_closures
    src/lambdas_and_closures.cpp)
