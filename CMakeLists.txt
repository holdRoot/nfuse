cmake_minimum_required(VERSION 3.13)
project(example)

set(CMAKE_CXX_COMPILER g++-8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall --std=c++0x -fpermissive -D_FILE_OFFSET_BITS=64 -D_DARWIN_USE_64_BIT_INODE -DFUSE_USE_VERSION=26 -I /usr/local/Cellar/boost/1.68.0_1/include -L /usr/local/Cellar/boost/1.68.0_1/lib -I ..")

include_directories(.)
include_directories(..)

add_executable(example
        hello.cpp
        helloFS.cpp
        helloFS.h)
