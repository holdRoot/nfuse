#include "src/include/nfuseFS.h"

#include <iostream>

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
    std::cout << "Last stats: " << std::endl;
    int res = 0;
    auto fd = open("nfusestore", 0);
    struct stat stat1{};
    res = fstat(fd, &stat1);
    std::cout << "Last modified: " << stat1.st_atim.tv_sec << std::endl;
    return res;
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
