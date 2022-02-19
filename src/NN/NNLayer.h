#include <vector>
#include <utility> 
#include "Edge.h"

#ifndef NNLAYER_H
#define NNLAYER_H

class NNLayer {

    float sigmoid(const float x) const;
    std::vector<Edge> edges;
    std::vector<float> values;

public:

    NNLayer(int numNodes, int numTargetNodes);
    std::vector<float> getValues() const;
    void setValues(const std::vector<float>& _values);
    void activation();
    void clear();
    void propagate(NNLayer& nextLayer);
    void add(int index, float value);
};

#endif // !NNLAYER_H