#include "nfuseFS.h"

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
main(int argc, char *argv[])
{
    std::cout << "Welcome to NFuse!" << std::endl;
    if (prep())
    {
        std::cerr << "Setup failed!" << std::endl;
    }

    NFuse fs;

    int status = fs.run(argc, argv);

    return status;
}
