#include <map>
#include <vector>
#include <string>
#include "NN/NN.h"
#include "Mutation/Mutater.h"
#include "Elite.h"
#include <atomic>
#include <thread>
#include <chrono>

#ifndef TRAINER_H
#define TRAINER_H

class Trainer {
    std::chrono::system_clock::time_point trainingStartTime;

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
    bool stopTraining();
    NN getBestNN();
    std::string getStatus();
};

#endif // !TRAINER_H
