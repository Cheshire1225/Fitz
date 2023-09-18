#include <stdint.h>

void prepTF64() {
    asm("mov tf+8, cs;"
        "pushf; pop tf+16;"
        "mov tf+24, rsp;"
        "mov tf+32, ss;"
        );
}