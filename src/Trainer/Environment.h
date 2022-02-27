#include <string>
#include "sol2/sol.hpp"
#include <vector>
#include "Model.h"
#include "NN/NN.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment {
    Model model;
    std::string luaScript;
    static constexpr int maxTurns = 10000;
public:

    Environment(std::string _luaScript);
    void reset();
    int score(NN& nn);
    int getNumObservations();
    int getNumActions();

};


#endif // !ENVIRONMENT_H
