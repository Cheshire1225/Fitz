#include <stdio.h>
#include "../fitz.h"

char SMEP = 1;
char SMAP = 2;
char ALL = 3;

long long setCR4(long long cr4, char mode) {
    if (mode == 1){
        int mask = ~(1 << 20);
        cr4 = cr4 & mask;
        return cr4;
    }
    else if (mode == 2){
        int mask = ~(1 << 21);
        cr4 = cr4 & mask;
        return cr4;
    }
    else if (mode == 3){
        int mask = ~(1 << 20);
        cr4 = cr4 & mask;        
        
        mask = ~(1 << 21);
        cr4 = cr4 & mask;
        return cr4;
    }
    else
        return -1;
}