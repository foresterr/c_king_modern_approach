remind: remind.o readline.o
	gcc -O -Wall -Wextra -Wno-unused-value -pedantic -std=c99 -o remind remind.o readline.o

remind.o: remind.c readline.h
	gcc -O -Wall -Wextra -Wno-unused-value -pedantic -std=c99 -c remind.c

readline.o: readline.c readline.h
	gcc -O -Wall -Wextra -Wno-unused-value -pedantic -std=c99 -c readline.c

clean:
	rm -f remind *.o
