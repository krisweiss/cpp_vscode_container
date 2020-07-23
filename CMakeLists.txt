cmake_minimum_required(VERSION 3.15)

project(new_project LANGUAGES CXX VERSION 0.0.1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(new_project new_project/main.cpp)

find_package(Catch2 REQUIRED)
add_executable(tests tests/unit_tests/main_test.cpp)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)