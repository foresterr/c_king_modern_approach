inventory: inventory2.o readline.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o inventory inventory2.o readline.o

inventory2.o: inventory2.c readline.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c inventory2.c

readline.o: readline.c readline.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c readline.c

clean:
	rm -f inventory *.o
