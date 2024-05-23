partialSums : partialSums.o
	gcc -g -ansi -Wall -pedantic partialSums.o -o partialSums
partialSums.o : partialSums.c
	gcc -c -ansi -Wall -pedantic partialSums.c -o partialSums.o
