main.exe: turtle.o main.o
	gcc turtle.o main.o -o turtle.exe -lm
turtle.o: turtle.c turtle.h
	gcc -c turtle.c -o turtle.o -lm
main.o: main.c turtle.h
	gcc -c main.c -o main.o
clean:
	rm *.o turtle.exe