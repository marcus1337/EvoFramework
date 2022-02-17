#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "NN/NN.h"

TEST_CASE("simple test", "[hello]") {
    REQUIRE(true == true);
}

TEST_CASE("simple_nn_test", "[my_nn]") {
    NN nn;
    REQUIRE(nn.foo() == 3);
}