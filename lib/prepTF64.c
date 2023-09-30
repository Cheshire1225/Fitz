#include <stdio.h>
#include <stdint.h>

void prepTF64(int verbose) {
    if (verbose)
        puts("Generating TrapFrame...");

    asm("mov tf+8, cs;"
        "pushf; pop tf+16;"
        "mov tf+24, rsp;"
        "mov tf+32, ss;"
        );
}