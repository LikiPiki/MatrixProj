cmake_minimum_required(VERSION 2.6)
project(laba)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SRC "*.cpp" "*.h")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})