#include "Server.h"
#include <iostream>
#include <signal.h>

Server::Server() {
    lua.open_libraries(sol::lib::base, sol::lib::table, sol::lib::coroutine, sol::lib::io, sol::lib::package, sol::lib::string, sol::lib::bit32, sol::lib::math, sol::lib::debug);

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
          if line then
            print("line: " .. line)
          end  
        if not err then client:send(line .. "\n") end
          client:close()
        end
    )";

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
    std::cout << "Interrupt signal (" << signum << ") received. Shutting down server." << std::endl;
    exit(signum);
}