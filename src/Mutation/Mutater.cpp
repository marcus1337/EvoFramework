#include "Mutater.h"

Mutater::Mutater() : randEngine(randDevice()) {
    setWeights();
}

void Mutater::setWeights()
{
    const int weightsRange = 1000;
    weightsDistribution = std::uniform_int_distribution<int>(0, weightsRange*2);
    for (int i = weightsRange; i > 0; i--) {
        weights.push_back((float)i / weightsRange);
    }
    weights.push_back(0);
    for (int i = 1; i <= weightsRange; i++) {
        weights.push_back(((float)i / weightsRange)*(-1.f));
    }    
}

float Mutater::getRandomWeight() {
    return weights[weightsDistribution(randEngine)];
}