#include <vector>
#include <utility> 
#include "Edge.h"

#ifndef NNLAYER_H
#define NNLAYER_H

class NNLayer {

    float sigmoid(float x);
    NNLayer* nextLayer = nullptr;
    std::vector<Edge> edges;
    std::vector<float> nodes;

public:

    NNLayer(int numNodes, int numTargetNodes);
    void activation();
    void clear();
    void propagate(NNLayer& nextLayer);
    void add(int index, float value);
};

#endif // !NNLAYER_H