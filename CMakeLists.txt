cmake_minimum_required(VERSION 3.15)
project(mytinystl)

set(CMAKE_CXX_STANDARD 14)

SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib )
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

ADD_SUBDIRECTORY(test)
add_executable(mytinystl main.cpp include1.0/envs_msg.h)