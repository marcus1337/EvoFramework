#include "RequestCommand.h"
#include <string>
#include <vector>
#include "Trainer/Trainer.h"

#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

class RequestFactory {
    Trainer trainer;
public:

    RequestCommand* createRequest(std::vector<std::string> args);

};

#endif
