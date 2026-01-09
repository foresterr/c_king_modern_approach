stackclient: stackclient.o stackADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o stackclient stackclient.o stackADT.o

stackclient.o: stackclient.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackclient.c

stackADT.o: stackADT.c stackADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stackADT.c

clean:
	rm -f stackclient *.o
