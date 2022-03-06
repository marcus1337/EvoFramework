#include "Server.h"
#include <iostream>
#include <signal.h>
#include <sstream>
#include <regex>
#include <iterator>

Server::Server() {
    lua.open_libraries(sol::lib::base, sol::lib::table, sol::lib::coroutine, sol::lib::io, sol::lib::package, sol::lib::string, sol::lib::bit32, sol::lib::math, sol::lib::debug);
    lua.set_function("handleRequest", &Server::handleRequest, this);

    serverScript = R"(
        local socket = require("socket")
        local server = assert(socket.bind("*", 1337))
        local ip, port = server:getsockname()
        print("Please telnet to localhost on port " .. port)
        print("After connecting, you have 10s to enter a line to be echoed")
        while 1 do
          local client = server:accept()
          client:settimeout(10)
          local line, err = client:receive("*l")
          if err then
              print("err: " .. err)
          end
          if not err then
              local serverReply = handleRequest(line)
              client:send(serverReply) 
          end
          client:close()
        end
    )";

}

std::string Server::handleRequest(std::string requestStr) {
    std::cout << "Received request {" << requestStr << "}\n";
    RequestCommand* command = requestFactory.createRequest(getArgs(requestStr));
    if (command == nullptr)
        return "Error: Command not found.\n";
    std::string response = command->execute();
    delete command;
    return response;
}

std::vector<std::string> Server::getArgs(std::string requestStr) {
    if (requestStr.empty())
        return { "none" };

    if (requestStr.starts_with("help")) {
        return { "help" };
    }

    return {"none"};
}

void Server::start() {
    signal(SIGINT, Server::interruptHandler);
    signal(SIGTERM, Server::interruptHandler);
    auto result = lua.safe_script(serverScript);
    if (!result.valid()) {
        sol::error err = result;
        std::cout << "Lua error: " << err.what() << "\n";
    }
}

void Server::interruptHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received. Shutting down server..." << std::endl;
    exit(signum);
}