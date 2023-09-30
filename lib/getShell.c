#include <stdio.h>
#include <unistd.h>

void getShell(int verbose) {
    if (verbose)
        puts("Spawning shell...");
        
    execl("/bin/sh", "sh", 0, NULL);
}