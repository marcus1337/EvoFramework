#include <string>
#include "Trainer/sol2/sol.hpp"
#include <vector>

#ifndef SERVER_H
#define SERVER_H

class Server {
    sol::state lua;

public:
    Server();
};

#endif