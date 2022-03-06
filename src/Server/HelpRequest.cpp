#include "HelpRequest.h"


HelpRequest::HelpRequest(std::vector<std::string> _args) : RequestCommand(_args) {

}

std::string HelpRequest::execute() {

    return "API for remote training of neural networks via genetic algorithms.\n\
Possible commands:\n\
help - Returns generic info about the API.\n\
start script:<lua script> - Starts training neural networks with the provided lua script. Returns \'Ok\', or an error message.\n\
stop - Stops training and returns a string representation of a neural network for the best generated solution, or an error message.\n\
stats - Info about the training progress.";
}