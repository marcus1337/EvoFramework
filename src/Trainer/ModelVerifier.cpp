#include "ModelVerifier.h"
#include "Model.h"

ModelVerifier::ModelVerifier(std::string _luaScript) : luaScript(_luaScript) {

}

bool ModelVerifier::verify() {

    return true;
}

void ModelVerifier::printInfo() {
    Model model(luaScript);
    std::cout << "#actions: " << model.getNumActions() << "\n";
    std::cout << "#observations: " << model.getNumObservations() << "\n";
    for (std::size_t i = 0; i < 10000; i++) {
        if (model.isDone())
            break;
        if ((i % 100) == 0) {
            std::cout << "isDone(): " << model.isDone() << ", score: " << model.getScore() << ", step: " << model.getTurn() << "\n";
            model.step(0);
        }
    }
}

std::string ModelVerifier::getExampleModel() {
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
    return exampleModelScript;
}