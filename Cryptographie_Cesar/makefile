main.exe: cesar.o main.o
	gcc cesar.o main.o -o cesar.exe
cesar.o: cesar.c cesar.h
	gcc -c cesar.c -o cesar.o
main.o: main.c cesar.h
	gcc -c main.c -o main.o
clean:
	rm *.o cesar.exe