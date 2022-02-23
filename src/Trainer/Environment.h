#include <string>
#include "sol2/sol.hpp"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment {

    std::string luaScript;
    sol::state lua;

public:

    Environment(std::string _luaScript);

};


#endif // !ENVIRONMENT_H
