CC=gcc
#Makro CC zawiera nazwę kompilatora
CFLAGS=-Wall -ansi -pedantic
#Makro CFLAGS zawiera parametry kompilatora
CLINK=-lm
#Makro CLINK zawiera opcje linkera.
program: nmea.o main.o 
	gcc -o program nmea.o main.o $(CFLAGS) $
#Wykorzystanie kompilatora gcc (makro CC) do zlinkowania 
#programu z opcją -lm (CLINK)
nmea.o: src/nmea.c src/nmea.h 
	gcc -c  $(CFLAGS) src/nmea.c -o nmea.o
main.o: main.c src/nmea.h
	gcc -c  $(CFLAGS) main.c -o main.o