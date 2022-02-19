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

TEST_CASE("deterministic", "[nn]") {
    NN nn({ 2, 3, 7, 2 });
    nn.propagate({ 1.f,0.f });
    std::vector<float> output1 = nn.getOutput();
    nn.propagate({ 1.f,0.f });
    std::vector<float> output2 = nn.getOutput();
    REQUIRE((output1[0] == output2[0] && output1[1] == output2[1]));
}