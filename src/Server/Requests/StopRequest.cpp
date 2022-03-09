#include "StopRequest.h"

StopRequest::StopRequest(std::vector<std::string> _args, Trainer& _trainer) : RequestCommand(_args), trainer(_trainer) {


}
std::string StopRequest::execute() {
    if (errorMsg != "")
        return errorMsg;
    bool wasTrainingStopped = trainer.stopTraining();
    if (!wasTrainingStopped) {
        return "Error: No training going on, can't stop.";
    }
    return trainer.getBestNN().getStringRepresentation();
};