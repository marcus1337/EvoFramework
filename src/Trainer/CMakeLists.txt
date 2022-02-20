add_library(Trainer Trainer.h Trainer.cpp "Elite.h" "Elite.cpp" "Environment.h" "Environment.cpp")

target_link_libraries(Trainer Mutation NN)