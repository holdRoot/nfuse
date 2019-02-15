cmake_minimum_required(VERSION 3.10)
project(llist)

set(CMAKE_CXX_STANDARD 17)

add_library(llist LList.cc Node.cc)
