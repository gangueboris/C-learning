main2.exe: turtle.o main3.o
	gcc turtle.o main3.o -o turtle.exe -lm
turtle.o: turtle.c turtle.h
	gcc -c turtle.c -o turtle.o -lm
main.o: main3.c turtle.h
	gcc -c main3.c -o main3.o
clean:
	rm *.o turtle.exe