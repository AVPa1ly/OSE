all: lab4

lab4: main.o invert.o
	gcc -o lab4 main.o invert.o

main.o: main.c
	gcc -c main.c

invert.o: invert.c
	gcc -c invert.c

clean:
	rm -rf *.o lab4
