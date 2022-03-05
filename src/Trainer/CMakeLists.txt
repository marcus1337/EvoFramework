

add_library(Trainer Trainer.h Trainer.cpp "Elite.h" "Elite.cpp" "Environment.h" "Environment.cpp" "sol2/sol.hpp" "sol2/config.hpp" "sol2/forward.hpp" "Model.h" "Model.cpp" "ModelVerifier.h" "ModelVerifier.cpp")

target_link_libraries(Trainer Mutation NN ${LUA_LIBRARIES})