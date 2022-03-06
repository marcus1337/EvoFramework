#include "RequestFactory.h"
#include "HelpRequest.h"

RequestCommand* RequestFactory::createRequest(std::vector<std::string> args) {
    RequestCommand* command = nullptr;
    std::string tag = args[0];
    args.erase(args.begin());

    if (tag == "help") {
        return new HelpRequest(args);
    }

    return command;
}