cmake_minimum_required(VERSION 3.13)
project(nfuse)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26")

add_executable(nfuse main.cpp misc/sample_hello.c)