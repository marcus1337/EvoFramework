add_subdirectory(Requests)

add_library(Server Server.h Server.cpp "RequestFactory.h" "RequestFactory.cpp")

target_link_libraries(Server Trainer Requests)