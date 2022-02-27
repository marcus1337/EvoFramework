#include "Environment.h"
#include <iostream>



Environment::Environment(std::string _luaScript) : luaScript(_luaScript), model(_luaScript) {

}

void Environment::reset() {
    model = Model(luaScript);
}

int Environment::score(NN& nn) {
    while (!model.isDone() && model.getTurn() < maxTurns) {
        std::vector<float> observation = model.getObservation();
        nn.propagate(observation);
        model.step(nn.getOutputIndex());
    }
    return model.getScore();
}

int Environment::getNumObservations() {
    return model.getNumObservations();
}

int Environment::getNumActions() {
    return model.getNumActions();
}