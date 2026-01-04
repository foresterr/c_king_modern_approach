proj6: proj6.o stack.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj6 proj6.o stack.o

proj6.o: proj6.c stack.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj6.c

stack.o: stack.c stack.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stack.c

clean:
	rm -f proj6 *.o
