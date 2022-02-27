#include "NN.h"

NN NN::makeDefaultNetwork(int numInput, int numOutput) {
    int numHiddenNodes = ((numInput/3)*2) + numOutput;
    NN nn({numInput, numHiddenNodes, numHiddenNodes, numOutput});
    return nn;
}

NN::NN(std::vector<int> numNodesInLayers) {
    for (std::size_t i = 0; i < numNodesInLayers.size(); i++) {
        int numNodes = numNodesInLayers[i];
        int numTargetNodes = 0;
        if (i != numNodesInLayers.size() - 1)
            numTargetNodes = numNodesInLayers[i + 1];
        NNLayer nnLayer(numNodes, numTargetNodes);
        layers.push_back(nnLayer);
    }
}

void NN::propagate(const std::vector<float>& inputValues) {
    clear();
    layers[0].setValues(inputValues);
    for (std::size_t i = 0; i < layers.size() - 1; i++) {
        layers[i].propagate(layers[i + 1]);
    }
}

void NN::clear() {
    for (auto& layer : layers) {
        layer.clear();
    }
}

int NN::getOutputIndex() const{
    std::vector<float> output = getOutput();
    float highest = output[0];
    int index = 0;
    for (std::size_t i = 1; i < output.size(); i++) {
        if (output[i] > highest) {
            highest = output[i];
            index = (int)i;
        }
    }

    return index;
}
std::vector<float> NN::getOutput() const{
    return layers[layers.size() - 1].getValues();
}

int NN::getNumLayers() const{
    return layers.size();
}
int NN::getNumNodesInLayer(int index) const{
    return layers[index].getNumNodes();
}
int NN::getNumEdges() const {
    int numEdges = 0;
    for (const NNLayer& layer : layers) {
        numEdges += layer.getNumEdges();
    }
    return numEdges;
}

void NN::setWeight(int index, float weight) {
    int layerIndex = 0;
    while (index >= layers[layerIndex].getNumEdges()) {
        index -= layers[layerIndex].getNumEdges();
        layerIndex++;
    }
    layers[layerIndex].setWeight(index, weight);
}

float NN::getWeight(int index) const {
    int layerIndex = 0;
    while (index >= layers[layerIndex].getNumEdges()) {
        index -= layers[layerIndex].getNumEdges();
        layerIndex++;
    }
    return layers[layerIndex].getEdge(index).weight;
}

std::vector<std::reference_wrapper<std::vector<Edge>>> NN::getEdgesRefs() {
    std::vector<std::reference_wrapper<std::vector<Edge>>> edgesRefs;
    for (auto& layer : layers) {
        edgesRefs.push_back(layer.getEdgesRef());
    }
    return edgesRefs;
}

std::reference_wrapper<std::vector<Edge>> NN::getEdgesRef(int index) {
    return layers[index].getEdgesRef();
}