#include "../fitz.h"

long long* ROPretUser64(struct trapFrame tf, long long swapgs, long long iretq) {
    static long long gadget[7] = { 0, };
    gadget[0] = swapgs;
    gadget[1] = iretq;
    gadget[2] = tf.user_rip;
    gadget[3] = tf.user_cs;
    gadget[4] = tf.user_rflags;
    gadget[5] = tf.user_rsp;
    gadget[6] = tf.user_ss;

    return gadget;    
}