#include <vector>
#include "NNLayer.h"

#ifndef NN_H
#define NN_H

class NN {

    std::vector<NNLayer> layers;
    void clear();

public:

    NN(std::vector<int> numNodesInLayers);
    void propagate(const std::vector<float>&);
    int getOutputIndex();
    std::vector<float> getOutput();

};

#endif // !NN_H