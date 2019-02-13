// Hello filesystem class definition

#ifndef __NFUSEFS_H_
#define __NFUSEFS_H_

#include "Fuse.h"
#include "Fuse-impl.h"

class NFuse : public Fusepp::Fuse<NFuse>
{
public:
  NFuse() {}
  ~NFuse() {}

  static int getattr(const char *, struct stat *, struct fuse_file_info *);

  static int readdir(const char *path, void *buf,
                     fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi,
                     enum fuse_readdir_flags);

  static int open(const char *path, struct fuse_file_info *fi);

  static int read(const char *path, char *buf, size_t size, off_t offset,
                  struct fuse_file_info *fi);
};

#endif
