#include <stdio.h>
#include <fcntl.h>


int openModule(char path[], int verbose){
    if (verbose)
        puts("Opening module...");

    int fd;
    if ((fd = open(path, O_RDWR)) < 0)  return -1;
    return fd;
}