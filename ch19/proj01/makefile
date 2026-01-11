proj1: proj1.o stackADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj1 proj1.o stackADT.o

proj1.o: proj1.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj1.c

stackADT.o: stackADT.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackADT.c

clean:
	rm -f proj1 *.o
