
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"
#include "Trainer/ModelVerifier.h"

int main(int argc, char* argv[]) {
    Trainer trainer(100, ModelVerifier::getExampleModel());
    bool startedTraining = trainer.train();
    std::cout << "started training? " << startedTraining << "\n";
    
    std::cin.get();

    return 0;
}