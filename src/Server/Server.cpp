#include "Server.h"
#include <iostream>

Server::Server() {
    lua.open_libraries(sol::lib::base, sol::lib::table, sol::lib::coroutine, sol::lib::io, sol::lib::package, sol::lib::string, sol::lib::bit32, sol::lib::math, sol::lib::debug);

    std::string _script = R"(
        print("lua...")
        local socket = require("socket")
        print("A")
        local server = assert(socket.bind("*", 0))
        print("B")
        local ip, port = server:getsockname()
        print("C")
        print("Please telnet to localhost on port " .. port)
        print("After connecting, you have 10s to enter a line to be echoed")

        while 1 do
          local client = server:accept()
          client:settimeout(10)
          local line, err = client:receive()
          if not err then client:send(line .. "\n") end
          client:close()
        end
    )";

    auto result = lua.safe_script(_script);
    if (!result.valid()) {
        std::cout << "lua error.\n";
        sol::error err = result;
        std::string what = err.what();
        std::cout << "script failed, error is: " << what << std::endl;
    }

    std::cout << "server constructor...\n";
}