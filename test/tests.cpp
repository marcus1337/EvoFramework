#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "NN/NN.h"
#include <iostream>

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

bool isValue(float value, float target, float epsilon = 0.01f) {
    return value + epsilon > target && value - epsilon < target;
}

TEST_CASE("propagation", "[nn]") {
    NN nn({ 1, 1 });
    nn.propagate({ 1.f });
    std::vector<float> output = nn.getOutput();
    REQUIRE(isValue(output[0], 0.73105f));

    nn = NN({ 5, 2 });
    nn.propagate({ 1.f, 1.f, 1.f, 1.f, 1.f });
    output = nn.getOutput();
    REQUIRE(isValue(output[0], 0.9933f));
}