#include <string>
#include "sol2/sol.hpp"

#ifndef MODEL_VERIFIER_H
#define MODEL_VERIFIRE_H

class ModelVerifier {
    sol::state lua;
    std::string luaScript;
public:
    ModelVerifier(std::string _luaScript);
    bool verify();
    void printInfo();
    static std::string getExampleModel();
};

#endif // !MODELVERIFIER_H
