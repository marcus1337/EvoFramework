
add_library(Server Server.h Server.cpp "RequestCommand.h" "RequestCommand.cpp" "HelpRequest.h" "HelpRequest.cpp" "RequestFactory.h" "RequestFactory.cpp" "StatsRequest.h" "StatsRequest.cpp" "StartRequest.h" "StartRequest.cpp" "StopRequest.h" "StopRequest.cpp")

target_link_libraries(Server Trainer)