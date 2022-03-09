#include "RequestCommand.h"
#include "Trainer/Trainer.h"

#ifndef STOPREQUEST_H
#define STOPREQUEST_H

class StopRequest : public RequestCommand {
    Trainer& trainer;
    std::string errorMsg;
public:
    StopRequest(std::vector<std::string> _args, Trainer& _trainer);
    std::string execute() override;

};

#endif // !STOPREQUEST_H