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
    std::string modelScript;
    std::vector<Elite> elites;

public:

    Trainer(int numElites, std::string _environmentScript);
    void evaluate();
};

#endif // !TRAINER_H
