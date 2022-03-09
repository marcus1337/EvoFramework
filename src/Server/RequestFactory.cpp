#include "RequestFactory.h"
#include "Server/Requests/HelpRequest.h"
#include "Server/Requests/StatsRequest.h"
#include "Server/Requests/StartRequest.h"
#include "Server/Requests/StopRequest.h"
#include "Server/Requests/TestRequest.h"

RequestCommand* RequestFactory::createRequest(std::vector<std::string> args) {
    RequestCommand* command = nullptr;
    std::string tag = args[0];
    args.erase(args.begin());

    if (tag == "help") {
        return new HelpRequest(args);
    }
    if (tag == "stats") {
        return new StatsRequest(args, trainer);
    }
    if (tag == "start") {
        return new StartRequest(args, trainer);
    }
    if (tag == "stop") {
        return new StopRequest(args, trainer);
    }
    if (tag == "test") {
        return new TestRequest(args);
    }

    return command;
}