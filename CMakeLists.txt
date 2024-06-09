cmake_minimum_required(VERSION 3.28)

# set c++ compiler as clang
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# set compile flags
set(CMAKE_CXX_FLAGS  "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG  "-g")

project("planning")


include_directories(./headers)

file(GLOB SRCES ./srcs)

add_executable(${PROJECT_NAME} app.cc ${SRCES})

