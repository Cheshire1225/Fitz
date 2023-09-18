#include "../fitz.h"

void retUser64(struct trapFrame tf) {
    asm("swapgs;"
        "mov %%rsp, %0;"
        "iretq;"
        : : "r" (&tf));
}