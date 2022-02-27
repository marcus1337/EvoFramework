#include "ModelVerifier.h"
#include "Model.h"
#include <iostream>

ModelVerifier::ModelVerifier(std::string _luaScript) : luaScript(_luaScript) {

}

bool ModelVerifier::testModel() {
    Model model(luaScript);
    int _action = 0;
    int _numActions = model.getNumActions();
    int _numObservations = model.getNumObservations();

    if (model.isDone())
        return false;

    for (int i = 0; i < 100000; i++) {
        model.step(_action);
        int score = model.getScore();
        if (score < 0)
            return false;
        if (model.isDone())
            break;
        auto vec = model.getObservation();
        if (vec.size() != _numObservations)
            return false;
        if (model.getNumActions() != _numActions)
            return false;
        _action = (_action + 1) % model.getNumActions();
    }

    return true;
}

bool ModelVerifier::verify() {

    if (!testCompile())
        return false;

    if (!testIsDone())
        return false;

    if (!testObserve())
        return false;

    if (!testNumActions())
        return false;

    if (!testScore())
        return false;

    if (!testObserveSize())
        return false;

    if (!testModel()) {
        std::cout << "Model error." << std::endl;
        return false;
    }

    return true;
}

bool ModelVerifier::testObserve()
{
    sol::protected_function problematicObserve = lua["observe"];
    sol::optional<sol::table> observeTable = problematicObserve();
    if (!observeTable) {
        std::cout << "observe() error." << std::endl;
        return false;
    }
    return true;
}

bool ModelVerifier::testObserveSize()
{
    sol::optional<int> numObserve = lua.script("return #observe()");
    if (!numObserve) {
        std::cout << "numObserve error." << std::endl;
        return false;
    }

    sol::table observation = lua["observe"]();
    if (observation.size() != numObserve) {
        std::cout << "numObserve size error." << std::endl;
        return false;
    }
}

bool ModelVerifier::testScore()
{
    sol::optional<int> scoreExist = lua["score"];
    if (!scoreExist) {
        std::cout << "score variable missing." << std::endl;
        return false;
    }
    return true;
}

bool ModelVerifier::testNumActions()
{
    sol::optional<int> numActionsExist = lua["numActions"];
    if (!numActionsExist) {
        std::cout << "numActions variable missing." << std::endl;
        return false;
    }
    return true;
}

bool ModelVerifier::testIsDone()
{
    sol::protected_function problematicIsDone = lua["isDone"];
    sol::optional<bool> isDoneResult = problematicIsDone();
    if (!isDoneResult) {
        std::cout << "isDone() error." << std::endl;
        return false;
    }
    return true;
}

bool ModelVerifier::testCompile()
{
    auto codeResult = lua.script(luaScript, &sol::script_default_on_error);
    if (!codeResult.valid()) {
        std::cout << "Compile error." << std::endl;
        return false;
    }
    return true;
}

void ModelVerifier::printInfo() {
    Model model(luaScript);
    std::cout << "#actions: " << model.getNumActions() << "\n";
    std::cout << "#observations: " << model.getNumObservations() << "\n";
    for (std::size_t i = 0; i < 10000; i++) {
        if (model.isDone())
            break;
        if ((i % 100) == 0) {
            std::cout << "isDone(): " << model.isDone() << ", score: " << model.getScore() << ", step: " << model.getTurn() << "\n";
            model.step(0);
        }
    }
}

std::string ModelVerifier::getExampleModel() {
    std::string exampleModelScript = R"(
        score = 0
        numActions = 3
        function observe() 
            return {0.1, 0.2, 0.3} 
        end
        function step(actionIndex) 
            score = score + 1 
        end
        function isDone() 
            return score > 10 
        end
    )";
    return exampleModelScript;
}

std::vector<std::string> ModelVerifier::getExampleWrongModels() {
    std::vector<std::string> _scripts;
    _scripts.push_back(R"(
            score = 0
            numActions = 3
            function observe() 
                return {0.1, 0.2, 0.3} 
            end
            function step(actionIndex) 
                score = score + 1 
            end
            function isDone() 
                return "not done"
            end
        )");

    _scripts.push_back(R"(
            score = 0
            function observe() 
                return {0.1, 0.2, 0.3} 
            end
            function step(actionIndex) 
                score = score + 1 
            end
            function isDone() 
                return score > 10 
            end
        )");
    _scripts.push_back(R"(
            score = 0
            numActions = 3
            function observe() 
                return {0.1, 0.2, 0.3} 
            end
            function step(actionIndex) 
                score = score + 1 
            end
            function isDone() 
                return score > 10 
            end
        )");
    return _scripts;
}