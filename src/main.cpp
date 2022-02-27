
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"
#include "Trainer/ModelVerifier.h"

int main(int argc, char* argv[]) {

    for (std::string _script : ModelVerifier::getExampleWrongModels()) {
        ModelVerifier verifier(_script);
        bool isValid = verifier.verify();
        std::cout << "Is code valid? " << isValid << "\n";
    }

    std::cout << "main function " << "\n";
    return 0;
}