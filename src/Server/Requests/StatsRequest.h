#include "RequestCommand.h"
#include "Trainer/Trainer.h"

#ifndef STATSREQUEST_H
#define STATSREQUEST_H

class StatsRequest : public RequestCommand {
    Trainer& trainer;

public:
    StatsRequest(std::vector<std::string> _args, Trainer& trainer);
    std::string execute() override;
};

#endif