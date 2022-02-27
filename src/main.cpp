
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"
#include "Trainer/ModelVerifier.h"

int main(int argc, char* argv[]) {
    Environment env(ModelVerifier::getExampleModel());
    std::cout << "main function " << ModelVerifier(ModelVerifier::getExampleModel()).verify() << "\n";
    NN nn = NN::makeDefaultNetwork(env.getNumObservations(), env.getNumActions());
    int score = env.score(nn);
    std::cout << "score: " << score << "\n";

    return 0;
}