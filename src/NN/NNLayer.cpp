#include "NNLayer.h"
#include <iostream>

float NNLayer::sigmoid(float x) {
    return 1.f / (1 + exp(-x));
}

NNLayer::NNLayer(int numNodes, int numTargetNodes) {
    nodes.resize(numNodes,0);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numTargetNodes; j++) {
            edges.push_back(Edge(i, j));
        }
    }
    
}

void NNLayer::activation() {
    for (std::size_t i = 0; i < nodes.size(); i++) {
        nodes[i] = sigmoid(nodes[i]);
    }
}

void NNLayer::clear() {
    for (std::size_t i = 0; i < nodes.size(); i++) {
        nodes[i] = 0;
    }
}

void NNLayer::propagate(NNLayer& nextLayer) {
    nextLayer.clear();
    for (const Edge& edge : edges) {
        nextLayer.add(edge.to, nodes[edge.from] * edge.weight);
    }
    nextLayer.activation();
}

void NNLayer::add(int index, float value) {
    nodes[index] += value;
}