#define CATCH_CONFIG_MAIN

#include "../../new_project/hello.cpp"
#include <catch2/catch.hpp>

TEST_CASE("Hello test") { REQUIRE(hello() == "Hello, new_project"); }