#include <string>
#include "Trainer/sol2/sol.hpp"
#include <vector>
#include "RequestCommand.h"
#include "RequestFactory.h"

#ifndef SERVER_H
#define SERVER_H

class Server {
    RequestFactory requestFactory;
    sol::state lua;
    std::string serverScript;
    static void interruptHandler(int signum);
    std::string handleRequest(std::string requestStr);
    std::vector<std::string> getArgs(std::string requestStr);
public:
    Server();
    void start();
};

#endif