cmake_minimum_required(VERSION 3.27)

# checkout current operating system
set(IS_LINUX FALSE)
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(IS_LINUX TRUE)
endif()

if (IS_LINUX)
	# set c++ compiler as clang
	set(CMAKE_C_COMPILER "clang")
	set(CMAKE_CXX_COMPILER "clang++")
endif()

# set compile flags
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_FLAGS  "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG  "-g")

# pass cmake compile test
if (NOT IS_LINUX)
	set(CMAKE_CXX_COMPILER_FORCED TRUE)
endif()


project("planning")

include_directories(./headers)

file(GLOB SRCES ./srcs)

add_executable(${PROJECT_NAME} app.cc ${SRCES})


