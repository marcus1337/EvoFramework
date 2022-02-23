

add_library(Trainer Trainer.h Trainer.cpp "Elite.h" "Elite.cpp" "Environment.h" "Environment.cpp" "sol2/sol.hpp" "sol2/config.hpp" "sol2/forward.hpp")

target_link_libraries(Trainer Mutation NN)