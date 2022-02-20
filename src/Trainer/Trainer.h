#include <map>
#include <vector>
#include <string>
#include "NN/NN.h"
#include "Mutation/Mutater.h"
#include "Elite.h"

#ifndef TRAINER_H
#define TRAINER_H

class Trainer {

    Mutater mutater;
    std::string _environmentScript;
    int numElites, numInputNodes, numOutputNodes;
    std::vector<Elite> elites;

public:

    Trainer(int _numElites, int _numInputNodes, int _numOutputNodes, std::string _environmentScript);

};

#endif // !TRAINER_H
