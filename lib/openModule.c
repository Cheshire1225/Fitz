#include <fcntl.h>

int openModule(char path[]){
    int fd;
    if ((fd = open(path, O_RDWR)) < 0)  return -1;
    return fd;
}