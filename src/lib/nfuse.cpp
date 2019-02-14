#include "src/include/nfuseFS.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

typedef std::vector<std::string> stringvec;

void read_directory(const std::string& name, stringvec& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != nullptr) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}

void
list_dir(const std::string &dir)
{
    stringvec v;
    read_directory(dir, v);

    for (const auto &item : v) {
        std::cout << item << std::endl;
    }
}


int
prep()
{
    int res = 0;

    system("sudo umount nfusestore");
    res = system("rm -rf nfusestore");
    if (res)
        return res;

    res = system("mkdir nfusestore");
    if (res)
        return res;

    return res;
}

int
test_bench()
{
    std::ifstream file;
    char cwd[FILENAME_MAX];
    getcwd(cwd, sizeof(cwd));

    auto dir = std::string(cwd);
    list_dir("nfusestore");

    auto my_file_name = dir + "/nfusestore/myfile";
    std::cout << my_file_name << std::endl;
    file.open(my_file_name);

    std::string buff;
    file >> buff;

    std::cout << buff << std::endl;

    return 0;
}

int
main(int argc, char *argv[])
{
    std::cout << "Welcome to NFuse!" << std::endl;
    if (prep())
    {
        std::cerr << "Setup failed!" << std::endl;
    }
    test_bench();

    NFuse fs;

    int status = fs.run(argc, argv);
    return status;
}
