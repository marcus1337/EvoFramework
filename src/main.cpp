#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"
#include "Trainer/ModelVerifier.h"
#include "Server/Server.h"

void testEnv() {
    Trainer trainer(100, ModelVerifier::getExampleModel());
    bool startedTraining = trainer.train();
    std::cout << "started training? " << startedTraining << "\n";
    std::cin.get();
    std::cout << "RESULT...\n";
    trainer.stopTraining();
    std::cout << trainer.getBestNN().getStringRepresentation() << "\n\n";
}

void testServer() {
    Server server;
    server.start();
}

int main(int argc, char* argv[]) {
    testServer();
    return 0;
}
