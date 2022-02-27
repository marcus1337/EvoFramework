#include <string>
#include "sol2/sol.hpp"
#include <vector>

#ifndef MODEL_VERIFIER_H
#define MODEL_VERIFIRE_H

class ModelVerifier {
    sol::state lua;
    std::string luaScript;
    bool testCompile();
    bool testObserve();
    bool testObserveSize();
    bool testScore();
    bool testNumActions();
    bool testIsDone();
    bool testModel();
public:
    ModelVerifier(std::string _luaScript);
    bool verify();
    void printInfo();
    static std::string getExampleModel();
    static std::vector<std::string> getExampleWrongModels();
};

#endif // !MODELVERIFIER_H
