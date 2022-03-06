
add_library(Server Server.h Server.cpp "RequestCommand.h" "RequestCommand.cpp" "HelpRequest.h" "HelpRequest.cpp" "RequestFactory.h" "RequestFactory.cpp")

target_link_libraries(Server Trainer)