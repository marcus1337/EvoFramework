#include "RequestCommand.h"
#include "Trainer/Trainer.h"
#include <vector>
#include <string>

#ifndef STARTREQUEST_H
#define STARTREQUEST_H


class StartRequest : public RequestCommand {
    Trainer& trainer;
    int numAIs;
    std::string luaScript;
    std::string errorMsg;
public:
    StartRequest(std::vector<std::string> _args, Trainer& _trainer);
    std::string execute() override;
};

#endif // !STARTREQUEST_H