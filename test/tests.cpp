#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "NN/NN.h"

TEST_CASE("edge count", "[nn]") {
    NN nn({ 2, 2 });
    REQUIRE(nn.getNumEdges() == 4);
    nn = NN({ 2, 3, 2 });
    REQUIRE(nn.getNumEdges() == 12);
    nn = NN({ 2, 3, 3, 2 });
    REQUIRE(nn.getNumEdges() == 21);
}

