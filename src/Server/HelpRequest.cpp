#include "HelpRequest.h"


HelpRequest::HelpRequest(std::vector<std::string> _args) : RequestCommand(_args) {

}

std::string HelpRequest::execute() {

    return "API for remote training of neural networks (NN) by using genetic algorithms (GA).\n\
Possible commands:\n\
help - Returns info about the API.\n\
start <number of AIs> script:<lua script> - Starts training NNs with the provided Lua script. <number of AIs> must be a positive integer that defines how many AIs can be tested in parallel by the GAs. Returns \'Ok\', or an error message.\n\
stop - Stops training and returns a string representation of the best generated NN, or an error message.\n\
stats - Info about the training progress.";
}