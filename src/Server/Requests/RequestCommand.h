#include <vector>
#include <string>


#ifndef REQUESTCOMMAND_H
#define REQUESTCOMMAND_H

class RequestCommand {

protected:
    std::vector<std::string> args;
    const std::string okResponse = "Ok";

public:
    RequestCommand(std::vector<std::string> _args);
    virtual std::string execute() = 0;
};

#endif
