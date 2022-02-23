#include "Environment.h"
#include <iostream>

struct vars {
    int boop = 0;
};

Environment::Environment(std::string _luaScript) : luaScript(_luaScript) {
    lua.new_usertype<vars>("vars", "boop", &vars::boop);
    lua.script("beep = vars.new()\n"
        "beep.boop = 1");
    std::cout << "LUA TEST: " << lua.get<vars>("beep").boop << "\n";
}