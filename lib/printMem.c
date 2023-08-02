#include <stdio.h>

void printMem(char buf[], int row){
    int x;
    int y;

    for (y = 0; y < row; y++)
    {
        for (x = 0; x < 16; x++) printf("%02x ", buf[y*16+x] & 0xff);
        printf("| ");
        for (x = 0; x < 16; x++) printf("%c", buf[y*16+x] & 0xff);
        printf("\n");
    }
}
