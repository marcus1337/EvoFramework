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
    int getOutputIndex() const;
    std::vector<float> getOutput() const;

    int getNumLayers() const;
    int getNumNodesInLayer(int index) const;
    int getNumEdges() const;

};

#endif // !NN_H