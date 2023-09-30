#include <stdio.h>
#include <stdint.h>

void printMem(const void* data, size_t size) {
    const uint8_t *buffer = (const uint8_t *)data;
    size_t lineCount = 0;

    for (size_t offset = 0; offset < size; offset += 16) {
        printf("%08lx   ", lineCount * 16);

        for (size_t i = offset; i < offset + 8 && i < size; i++) {
            printf("%02x ", buffer[i]);
        }

        printf(" ");

        for (size_t i = offset+8; i < offset + 16 && i < size; i++) {
            printf("%02x ", buffer[i]);
        }

        if (offset+16 >= size)
            for (int i = 0; i < (offset+16 - size)*3; i++)
                printf(" ");

        printf("  ");
        for (size_t i = offset; i < offset + 16 && i < size; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                putchar(buffer[i]);
            } else {
                putchar('.');
            }
        }

        putchar('\n');
        lineCount++;
    }
}