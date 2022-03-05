#include "NNLayer.h"
#include <iostream>
#include <math.h>

float NNLayer::sigmoid(const float x) const {
    return 1.f / (1 + exp(-x));
}

NNLayer::NNLayer(int numNodes, int numTargetNodes) {
    values.resize(numNodes, 0);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numTargetNodes; j++) {
            edges.push_back(Edge(i, j));
        }
    }

}

void NNLayer::activation() {
    for (std::size_t i = 0; i < values.size(); i++) {
        values[i] = sigmoid(values[i]);
    }
}

void NNLayer::clear() {
    for (std::size_t i = 0; i < values.size(); i++) {
        values[i] = 0;
    }
}

void NNLayer::propagate(NNLayer& nextLayer) {
    for (const Edge& edge : edges) {
        nextLayer.add(edge.to, values[edge.from] * edge.weight);
    }
    nextLayer.activation();
}

void NNLayer::add(int index, float value) {
    values[index] += value;
}

std::vector<float> NNLayer::getValues() const {
    return values;
}

void NNLayer::setValues(const std::vector<float>& _values) {
    for(std::size_t i = 0; i < _values.size(); i++)
        values[i] = _values[i];
}

int NNLayer::getNumNodes() const {
    return values.size();
}

int NNLayer::getNumEdges() const {
    return edges.size();
}

Edge NNLayer::getEdge(int index) const {
    return edges[index];
}

void NNLayer::setWeight(int index, float weight) {
    edges[index].weight = weight;
}

std::vector<Edge>& NNLayer::getEdgesRef() {
    return edges;
}