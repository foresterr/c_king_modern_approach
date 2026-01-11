justify: justify.o word.o line.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c justify.c

word.o: word.c word.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c word.c

line.o: line.c line.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c line.c

clean:
	rm -f justify *.o 
