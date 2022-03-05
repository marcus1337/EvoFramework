#include "Trainer.h"
#include <iostream>
#include "Environment.h"
#include <algorithm>
#include <functional>
#include <future>
#include <execution>

Trainer::Trainer(int numElites, std::string _modelScript) : isTraining(false) {
    reset(numElites, _modelScript);
}

bool Trainer::reset(int numElites, std::string _environmentScript) {
    if (isTraining)
        return false;

    elites.clear();
    elites.reserve(numElites);

    modelScript = _environmentScript;
    Environment env(modelScript);
    int numIn = env.getNumObservations();
    int numOut = env.getNumActions();
    for (int i = 0; i < numElites; i++) {
        NN nn = NN::makeDefaultNetwork(numIn, numOut);
        mutater.randomize(nn);
        elites.push_back(Elite(nn));
    }
    bestElite = Elite();
    return true;
}

Trainer::~Trainer() {
    stopTraining();
}

void Trainer::evaluate() {
    std::for_each(
        std::execution::par_unseq,
        elites.begin(),
        elites.end(),
        [&modelScript = modelScript](Elite& elite)
        {
            Environment env(modelScript);
            elite.fitness = env.score(elite.nn);
        });
}

void Trainer::select() {
    auto elitePtr = std::max_element(elites.begin(), elites.end(),
        [](const Elite& a, const Elite& b)
        {
            return a.fitness < b.fitness;
        });
    bestElite = *elitePtr;
    bestElite.fitness = 0;
    for (std::size_t i = 0; i < elites.size(); i++) {
        elites[i] = bestElite;
    }
}

void Trainer::mutate() {
    float numElites = (float)elites.size();
    float mutateDelta = 1.0f / numElites;
    for (std::size_t i = 1; i < elites.size(); i++) {
        mutater.mutate(elites[i].nn, 1.0f - (mutateDelta * (float)i));
    }
}

void Trainer::stopTraining() {
    if (trainingThread.joinable()) {
        isTraining = false;
        trainingThread.join();
    }
}

bool Trainer::train() {
    if (isTraining)
        return false;
    isTraining = true;
    trainingThread = std::thread{ [&]() {
        while (isTraining) {
            evaluate();
            select();
            mutate();
        }
    } };
    return true;
}

NN Trainer::getBestNN() {
    return bestElite.nn;
}