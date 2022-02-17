cmake_minimum_required(VERSION 3.16)

project(EvoFramework)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(NN)
list(APPEND EXTRA_LIB_DIRS "NN")
list(APPEND EXTRA_INCLUDE_DIRS "NN")
list(APPEND EXTRA_LINK_DIRS NN)

include_directories("${PROJECT_SOURCE_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIB_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LINK_DIRS})

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-error=invalid-offsetof -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=sign-compare -Wno-error=reorder -std=c++2a")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")
endif(UNIX)