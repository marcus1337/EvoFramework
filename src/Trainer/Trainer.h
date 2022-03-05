#include <map>
#include <vector>
#include <string>
#include "NN/NN.h"
#include "Mutation/Mutater.h"
#include "Elite.h"
#include <atomic>
#include <thread>

#ifndef TRAINER_H
#define TRAINER_H

class Trainer {

    Mutater mutater;
    std::string modelScript;
    std::vector<Elite> elites;
    Elite bestElite;
    void evaluate();
    void select();
    void mutate();

    std::atomic<bool> isTraining;
    std::thread trainingThread;

public:

    Trainer(int numElites = 0, std::string _environmentScript = "");
    bool reset(int numElites, std::string _environmentScript);
    ~Trainer();
    bool train();
    void stopTraining();
    NN getBestNN();
};

#endif // !TRAINER_H
