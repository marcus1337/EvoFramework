#include "RequestCommand.h"
#include <string>

#ifndef TESTREQUEST_H
#define TESTREQUEST_H

class TestRequest : public RequestCommand {
    std::string errorMsg;
    std::string luaScript;

public:
    TestRequest(std::vector<std::string> _args);
    std::string execute() override;
};


#endif