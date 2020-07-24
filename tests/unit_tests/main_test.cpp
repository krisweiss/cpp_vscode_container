#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../new_project/hello.cpp"

TEST_CASE("Hello test") { REQUIRE(hello() == "Hello, new_project"); }