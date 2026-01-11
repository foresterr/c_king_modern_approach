proj02: proj02.o stackADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj02 proj02.o stackADT.o

proj02.o: proj02.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj02.c

stackADT.o: stackADT.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackADT.c

clean:
	rm -f proj02 *.o
