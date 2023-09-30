#include <stdio.h>
#include <unistd.h>

void getShell(_Bool verbose) {
    if (verbose)
        puts("Spawning shell...");
        
    execl("/bin/sh", "sh", 0, NULL);
}