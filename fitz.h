#ifndef FITZ_H
#define FITZ_H

#include <stdint.h>
#include <stdio.h>

struct trapFrame {
    uint64_t user_rip;
    uint64_t user_cs;
    uint64_t user_rflags;
    uint64_t user_rsp;
    uint64_t user_ss;
} __attribute__((packed));

extern char SMEP;
extern char SMAP;
extern char ALL;

void printMem(const void* data, size_t size);
int openModule(char path[], _Bool verbose);
void retUser64(struct trapFrame tf);
long long* ROPretUser64(struct trapFrame tf, long long swapgs, long long iretq, _Bool verbose);
long long* KPTIROPretUser64(struct trapFrame tf, long long swapgs_restore_regs_and_return_to_usermode, _Bool verbose);
void prepTF64(uint64_t *user_rip, _Bool verbose);
void getShell(_Bool verbose);
long long setCR4(long long cr4, char mode, _Bool verbose);

#endif
