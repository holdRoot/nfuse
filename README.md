# NFuse: FUSE + NFS
## The What:
- NFuse is a FUSE based user-space filesystem that follows the NFS interface. 
- It's a simple filesystem capable of remote file transfer/storage.
- It uses an internal B+Tree data-structure to manage the filesystem. 
## Dependencies:
- `libfuse`
- `gRPC`
- C++ version of <a href="https://github.com/libfuse/libfuse/releases/tag/fuse-2.9.7">FUSE: Filesystem in Userspace</a> -  example/hello.c 
