inventory: inventory.o readline.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o inventory inventory.o readline.o

inventory.o: inventory.c readline.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c inventory.c

readline.o: readline.c readline.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c readline.c

clean:
	rm -f inventory *.o
