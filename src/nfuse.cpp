#include "nfuseFS.h"

int main(int argc, char *argv[])
{

  	NFuse fs;

  	int status = fs.run(argc, argv);

  	return status;
}
