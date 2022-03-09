add_library(Requests HelpRequest.h HelpRequest.cpp RequestCommand.cpp RequestCommand.h StartRequest.h StartRequest.cpp StatsRequest.h StatsRequest.cpp StopRequest.h StopRequest.cpp "TestRequest.h" "TestRequest.cpp")

target_link_libraries(Requests Trainer)