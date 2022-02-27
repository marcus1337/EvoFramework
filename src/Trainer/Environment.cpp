#include "Environment.h"
#include <iostream>



Environment::Environment(std::string _luaScript) : model(_luaScript) {
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

void Environment::reset() {
   
}

int Environment::score(NN& nn) {

    return 0;
}