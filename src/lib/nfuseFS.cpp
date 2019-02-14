#include "src/include/nfuseFS.h"

#include <iostream>

#include "Fuse-impl.h"

static const std::string root_path = "/";

// TODO : Test data
static const std::string hello_str = "Yoooo!";
static const std::string hello_path = "/myfile";

NFuse::NFuse() {}

NFuse::~NFuse() {}

int
NFuse::getattr(const char *path, struct stat *stbuf, struct fuse_file_info *)
{
    int res = 0;

    memset(stbuf, 0, sizeof(struct stat));
    if (path==root_path)
    {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
    }
    else if (path==hello_path)
    {
        stbuf->st_mode = S_IFREG | 0444;
        stbuf->st_nlink = 1;
        stbuf->st_size = hello_str.length();
    }
    else
        res = -ENOENT;

    return res;
}

int
NFuse::readdir(const char *path, void *buf, fuse_fill_dir_t filler,
               off_t, struct fuse_file_info *, enum fuse_readdir_flags)
{
    if (path!=root_path)
        return -ENOENT;

    filler(buf, ".", NULL, 0, FUSE_FILL_DIR_PLUS);
    filler(buf, "..", NULL, 0, FUSE_FILL_DIR_PLUS);
    filler(buf, hello_path.c_str() + 1, NULL, 0, FUSE_FILL_DIR_PLUS);

    return 0;
}

int
NFuse::open(const char *path, struct fuse_file_info *fi)
{
    if (path!=hello_path)
        return -ENOENT;

    if ((fi->flags & 3)!=O_RDONLY)
        return -EACCES;

    return 0;
}

int
NFuse::read(const char *path, char *buf, size_t size, off_t offset,
            struct fuse_file_info *)
{
    if (path!=hello_path)
        return -ENOENT;

    size_t len;
    len = hello_str.length();
    if ((size_t) offset < len)
    {
        if (offset + size > len)
            size = len - offset;
        memcpy(buf, hello_str.c_str() + offset, size);
    }
    else
        size = 0;

    return size;
}
