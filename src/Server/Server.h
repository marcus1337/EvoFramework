#include <string>
#include "Trainer/sol2/sol.hpp"
#include <vector>

#ifndef SERVER_H
#define SERVER_H

class Server {
    sol::state lua;
    std::string serverScript;
    static void interruptHandler(int signum);
    std::string handleRequest(std::string requestStr);
public:
    Server();
    void start();
};

#endif