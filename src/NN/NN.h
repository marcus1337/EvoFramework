#include <vector>
#include "NNLayer.h"
#include <functional>

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
    void setWeight(int index, float weight);
    float getWeight(int index) const;
    std::vector<std::reference_wrapper<std::vector<Edge>>> getEdgesRefs();
    std::reference_wrapper<std::vector<Edge>> getEdgesRef(int index);

};

#endif // !NN_H