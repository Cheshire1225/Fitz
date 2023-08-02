#ifndef FITZ_H
#define FITZ_H

#include <stdint.h>

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

void printMem(char buf[], int row);
int openModule(char path[]);
void retUser64(struct trapFrame tf);
long long* ROPretUser64(struct trapFrame tf, long long swapgs, long long iretq);
void prepTF64();
void getShell();
long long setCR4(long long cr4, char mode);

#endif