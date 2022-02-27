#include <string>
#include "sol2/sol.hpp"
#include <vector>

#ifndef MODEL_H
#define MODEL_H

class Model {
    std::vector<float> observation;
    int turn;
    std::string luaScript;
    sol::state lua;
    void setObservation();
public:

    Model(std::string luaScript);
    void step(int _action);
    int getTurn();
    int getNumObservations();
    int getNumActions();
    int getScore();
    bool isDone();
};

#endif