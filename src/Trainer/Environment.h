#include <string>
#include "sol2/sol.hpp"
#include <vector>
#include "Model.h"
#include "NN/NN.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment {
    Model model;
public:

    Environment(std::string _luaScript);
    void reset();
    int score(NN& nn);

};


#endif // !ENVIRONMENT_H
