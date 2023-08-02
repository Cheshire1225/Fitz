#!/bin/bash
gcc -c test.c -O0 -o test.o -masm=intel
gcc -o $1 $1.o -O0 -L.. -l:fitz.a --static
