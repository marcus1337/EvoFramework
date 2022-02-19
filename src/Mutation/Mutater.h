#include "NN/NN.h"
#include <random>

#ifndef MUTATER_H
#define MUTATER_H

class Mutater {

    std::random_device randDevice;
    std::mt19937 randEngine;
    std::uniform_int_distribution<int> weightsDistribution;
    std::vector<float> weights;

    void setWeights();

public:
    float getRandomWeight();

    Mutater();

};

#endif