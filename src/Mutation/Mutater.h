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
    int randInt(int from, int to);

public:
    float getRandomWeight();
    void randomize(NN& nn);
    void mutate(NN& nn, float mutationRate = 1.f);

    Mutater();

};

#endif