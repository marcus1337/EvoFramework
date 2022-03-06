#include "RequestCommand.h"
#include <string>
#include <vector>

#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

class RequestFactory {

public:

    RequestCommand* createRequest(std::vector<std::string> args);

};

#endif
