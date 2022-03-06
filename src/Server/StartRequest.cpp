#include "StartRequest.h"
#include <ctype.h>
#include "Trainer/ModelVerifier.h"

StartRequest::StartRequest(std::vector<std::string> _args, Trainer& _trainer) : RequestCommand(_args), trainer(_trainer) {
    if (args.size() != 2) {
        errorMsg = "Error: Missing argument(s).";
        return;
    }
    std::string numAIsStr = args[0];
    luaScript = args[1];
    for (char c : numAIsStr) {
        if (!isdigit((unsigned char)c)) {
            errorMsg = "Error: <number of AIs> must be a positive integer.";
            return;
        }
    }
    numAIs = std::stoi(numAIsStr);
    if (numAIs <= 0) {
        errorMsg = "Error: Malformed <number of AIs>.";
        return;
    }
    ModelVerifier modelVerifier(luaScript);
    if (!modelVerifier.verify()) {
        errorMsg = "Error: Something wrong with provided Lua script.";
        return;
    }

}
std::string StartRequest::execute() {
    if (errorMsg != "")
        return errorMsg;
    bool isNewStart = trainer.reset(numAIs, luaScript);    
    if (!isNewStart) {
        return "Error: Already training.";
    }
    return okResponse;
};