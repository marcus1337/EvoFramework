#include "RequestFactory.h"
#include "HelpRequest.h"
#include "StatsRequest.h"
#include "StartRequest.h"
#include "StopRequest.h"

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

    return command;
}