cmake_minimum_required( VERSION 3.10 )
project( nfuse )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_VERBOSE_MAKEFILE ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# External libraries
add_subdirectory( external/llist )

find_package( Protobuf REQUIRED )

include_directories( . )
include_directories( generated )
include_directories( src/include )
include_directories( external )
include_directories( /usr/local/include/fuse3 )

# gRPC configs
include_directories( /usr/local/include )
link_directories( /usr/local/lib )

set( PROTO_PATH "${CMAKE_SOURCE_DIR}/protos" )
set( NFUSE_PROTO "${PROTO_PATH}/nfuse.proto" )
set( GENERATED_PROTOBUF_PATH "${CMAKE_BINARY_DIR}/generated" )
file( MAKE_DIRECTORY ${GENERATED_PROTOBUF_PATH} )

set( NFUSE_PB_CPP_FILE "${GENERATED_PROTOBUF_PATH}/nfuse.pb.cc" )
set( NFUSE_PB_H_FILE "${GENERATED_PROTOBUF_PATH}/nfuse.pb.h" )
set( NFUSE_GRPC_PB_CPP_FILE "${GENERATED_PROTOBUF_PATH}/nfuse.grpc.pb.cc" )
set( NFUSE_GRPC_PB_H_FILE "${GENERATED_PROTOBUF_PATH}/nfuse.grpc.pb.h" )
add_custom_command (
    OUTPUT "${NFUSE_PB_H_FILE}"
    "${NFUSE_PB_CPP_FILE}"
    "${NFUSE_GRPC_PB_H_FILE}"
    "${NFUSE_GRPC_PB_CPP_FILE}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "--proto_path=${PROTO_PATH}"
    "--cpp_out=${GENERATED_PROTOBUF_PATH}"
    "${NFUSE_PROTO}"
    COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
    ARGS "--proto_path=${PROTO_PATH}"
    "--grpc_out=${GENERATED_PROTOBUF_PATH}"
    "--plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin"
    "${NFUSE_PROTO}"
	)
set( GENERATED_PROTOBUF_FILES ${NFUSE_PB_H_FILE} ${NFUSE_PB_CPP_FILE}
    ${NFUSE_GRPC_PB_H_FILE} ${NFUSE_GRPC_PB_CPP_FILE} )

include_directories( ${GENERATED_PROTOBUF_PATH} )
link_libraries( grpc++_unsecure grpc gpr ${PROTOBUF_LIBRARY} )

add_executable( server src/lib/grpc/server.cc ${GENERATED_PROTOBUF_FILES} )
add_executable( client src/lib/grpc/client.cc ${GENERATED_PROTOBUF_FILES} )

add_executable( nfuse
    src/lib/nfuse.cc
    src/lib/nfuseFS.cc
    src/include/nfuseFS.h
    src/lib/fs/fcache.cc
    Fuse-impl.h
    Fuse.cpp
    Fuse.h )

target_link_libraries( nfuse llist pthread fuse3 )

