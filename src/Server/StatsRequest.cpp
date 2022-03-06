#include "StatsRequest.h"

StatsRequest::StatsRequest(std::vector<std::string> _args, Trainer& _trainer) : RequestCommand(_args), trainer(_trainer) {

}
std::string StatsRequest::execute() {

    return "Status:\n" + trainer.getStatus();
};