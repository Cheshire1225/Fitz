lib_build :
	gcc -masm=intel -O0 -c lib/*.c
	mv *.o lib/
	ar rcs fitz.a lib/*.o

build :
	gcc -c $(src).c -O0 -o $(src).o -masm=intel
	gcc -o $(src) $(src).o -O0 -L.. -l:fitz.a --static

clean :
	rm lib/*.o fitz.a
