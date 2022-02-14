cmake_minimum_required(VERSION 3.16)

project(EvoFramework)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

include_directories("${PROJECT_SOURCE_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIB_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LINK_DIRS})