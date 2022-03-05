#include "HelpRequest.h"


HelpRequest::HelpRequest(std::vector<std::string> _args) : RequestCommand(_args) {

}

std::string HelpRequest::execute() {

    return "test 123";
}