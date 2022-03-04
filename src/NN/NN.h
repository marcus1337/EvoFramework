#include <vector>
#include "NNLayer.h"
#include <functional>
#include <string>

#ifndef NN_H
#define NN_H

class NN {

    std::vector<NNLayer> layers;
    void clear();

public:

    static NN makeDefaultNetwork(int numInput, int numOutput);
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

    std::string getStringRepresentation();

};

#endif // !NN_H