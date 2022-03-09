#include "RequestCommand.h"

#ifndef HELPREQUEST_H
#define HELPREQUEST_H

class HelpRequest : public RequestCommand {

public:

    HelpRequest(std::vector<std::string> _args);

    std::string execute() override;

};

#endif // !HELPREQUEST_H
