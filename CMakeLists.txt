cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project (DutManager)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
