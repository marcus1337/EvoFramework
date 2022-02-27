
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"
#include "Trainer/ModelVerifier.h"

int main(int argc, char* argv[]) {

    ModelVerifier verifier(ModelVerifier::getExampleModel());
    verifier.printInfo();

    std::cout << "main function " << "\n";

    return 0;
}