lib_build :
	gcc -masm=intel -O0 -c lib/*.c
	mv *.o lib/
	ar rcs fitz.a lib/*.o

build :
	gcc -o $(src) $(src).c -masm=intel -O0 -L. -l:fitz.a --static

clean :
	rm lib/*.o fitz.a
