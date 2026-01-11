proj01: proj01.o stackADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj01 proj01.o stackADT.o

proj01.o: proj01.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj01.c

stackADT.o: stackADT.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackADT.c

clean:
	rm -f proj01 *.o
