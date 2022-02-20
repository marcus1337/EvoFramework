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

void Mutater::randomize(NN& nn) {
    auto edgeRefs = nn.getEdgesRefs();
    for (auto& edgeVecWrapped : edgeRefs) {
        std::vector<Edge>& edgeVec = edgeVecWrapped.get();
        for (std::size_t i = 0; i < edgeVec.size(); i++) {
            edgeVec[i].weight = getRandomWeight();
        }
    }
}

int Mutater::randInt(int from, int to) {
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(randEngine);
}

void Mutater::mutate(NN& nn, float mutationRate) {
    //mutationRate is [0,1] and decides how far off a weight change can deviate from its previous value.
    int numLayers = nn.getNumLayers();
    int layerIndex = randInt(0, numLayers - 2);
    std::vector<Edge>& edges = nn.getEdgesRef(layerIndex).get();
    int edgeIndex = randInt(0, edges.size() - 1);
    edges[edgeIndex].weight = getRandomWeight();
}