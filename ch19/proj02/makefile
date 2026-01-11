proj2: proj2.o stackADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj2 proj2.o stackADT.o

proj2.o: proj2.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj2.c

stackADT.o: stackADT.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackADT.c

clean:
	rm -f proj2 *.o
