#!/bin/bash
gcc -c $1.c -O0 -o $1.o -masm=intel
gcc -o $1 $1.o -O0 -L.. -l:fitz.a --static
