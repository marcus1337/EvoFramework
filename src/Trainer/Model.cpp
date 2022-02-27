#include "Model.h"
#include "Model.h"


Model::Model(std::string _luaScript) : luaScript(_luaScript), turn(0) {
    lua.open_libraries(sol::lib::base, sol::lib::table);
    lua.script(luaScript);
    observation.resize(getNumObservations());
    setObservation();
}

void Model::step(int _action) {
    turn++;
    lua["step"](_action);
    setObservation();
}

void Model::setObservation()
{
    sol::table obsTable = lua["observe"]();
    for (std::size_t i = 1; i <= obsTable.size(); i++) {
        observation[i-1] = obsTable[i];
    }
}

int Model::getTurn() {
    return turn;
}
int Model::getNumObservations() {    
    return lua.script("return #observe()");
}

int Model::getNumActions() {
    return lua["numActions"];
}

int Model::getScore() {
    return lua["score"];
}

bool Model::isDone() {
    return lua["isDone"]();
}