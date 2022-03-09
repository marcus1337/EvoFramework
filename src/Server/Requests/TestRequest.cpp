#include "TestRequest.h"
#include "Trainer/ModelVerifier.h"

TestRequest::TestRequest(std::vector<std::string> _args) : RequestCommand(_args) {
    if (args.size() != 1) {
        errorMsg = "Error: Wrong number of argument.";
        return;
    }
    luaScript = args[0];
}

std::string TestRequest::execute() {
    if (errorMsg != "")
        return errorMsg;

    ModelVerifier modelVerifier(luaScript);
    if (!modelVerifier.verify()) {
        return modelVerifier.getErrorMsg();
    }

    return okResponse;
}