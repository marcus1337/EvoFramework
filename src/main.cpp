
#include <iostream>
#include "NN/NN.h"
#include "NNLayer.h"
#include "Mutation/Mutater.h"
#include "Trainer/Trainer.h"
#include "Trainer/Environment.h"
#include "Trainer/Model.h"

int main(int argc, char* argv[]) {

    std::string exampleModelScript = R"(
        score = 0
        numActions = 3
        function observe() 
            return {0.1, 0.2, 0.3} 
        end
        function step(actionIndex) 
            score = score + 1 
        end
        function isDone() 
            return score > 10 
        end
    )";
    Environment env(exampleModelScript);

    std::cout << "main function " << "\n";

    return 0;
}