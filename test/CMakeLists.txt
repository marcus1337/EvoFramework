if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)


find_package(Catch2 3 REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/deps/Catch2")

include_directories (${PROJECT_SOURCE_DIR}/src)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain NN)
