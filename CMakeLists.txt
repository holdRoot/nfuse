cmake_minimum_required(VERSION 3.10)
project(nfuse)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)


include_directories(.)
include_directories(src)
include_directories(/usr/local/include/fuse3)

add_executable(nfuse
        src/nfuse.cpp
        src/nfuseFS.cpp
        src/nfuseFS.h
        Fuse-impl.h
        Fuse.cpp
        Fuse.h)

target_link_libraries(nfuse
        pthread
        fuse3
        )
