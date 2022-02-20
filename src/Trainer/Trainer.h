#include <map>
#include <vector>
#include <string>
#include "NN/NN.h"

#ifndef TRAINER_H
#define TRAINER_H

class Trainer {

    std::string _environmentScript;
    int numAIs, numInputNodes, numOutputNodes;
    std::vector<NN> elites;

public:

    Trainer(int _numAIs, int _numInputNodes, int _numOutputNodes, std::string _environmentScript);

};

#endif // !TRAINER_H
