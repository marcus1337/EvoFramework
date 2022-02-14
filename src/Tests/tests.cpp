#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("simple test", "[hello]") {
    REQUIRE(true == true);
}