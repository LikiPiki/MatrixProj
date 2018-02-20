cmake_minimum_required(VERSION 2.6)
project(laba)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SRC "*.cpp" "*.h")

FIND_PATH(SDL SDL2/SDL.h)
message("find " ${SDL})

add_executable(${PROJECT_NAME} ${SRC})
include_directories(${SDL})
target_link_libraries(${PROJECT_NAME} ${SDL})