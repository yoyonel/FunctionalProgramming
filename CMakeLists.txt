cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(FplusMinimalExternalExample)
set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)
ExternalProject_Add(functional_plus
  GIT_REPOSITORY https://github.com/Dobiasd/FunctionalPlus.git
  GIT_TAG master

  SOURCE_DIR "${CMAKE_BINARY_DIR}/thirdparty/fplus"

  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""

  LOG_DOWNLOAD ON
  LOG_BUILD ON
)
set(FPLUS_INCLUDE_DIR ${CMAKE_BINARY_DIR}/thirdparty/fplus/include)
include_directories(${FPLUS_INCLUDE_DIR})

# https://stackoverflow.com/questions/41361631/optimize-in-cmake-by-default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(fplus_test src/fplus_test.cpp)
add_dependencies(fplus_test functional_plus)

add_executable(square_values src/square_values.cpp)
add_dependencies(square_values functional_plus)

add_executable(currying src/currying.cpp)
add_dependencies(currying functional_plus)

add_executable(forward_application src/forward_application.cpp)
add_dependencies(forward_application functional_plus)

add_executable(forward_application_2 src/forward_application_2.cpp)
add_dependencies(forward_application_2 functional_plus)

add_executable(Correctness_follows_from_expressiveness src/Correctness_follows_from_expressiveness.cpp)
add_dependencies(Correctness_follows_from_expressiveness functional_plus)

add_executable(lambdas_and_closures src/lambdas_and_closures.cpp)
add_dependencies(lambdas_and_closures functional_plus)

add_executable(sql_analogy src/sql_analogy.cpp)
add_dependencies(sql_analogy functional_plus)

add_executable(composition src/composition.cpp)
add_dependencies(composition functional_plus)

add_executable(function_composition_exercice src/function_composition_exercice.cpp)
add_dependencies(function_composition_exercice functional_plus)
