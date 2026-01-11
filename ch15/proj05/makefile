proj06: proj06.o stack.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o proj06 proj06.o stack.o

proj06.o: proj06.c stack.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c proj06.c

stack.o: stack.c stack.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c stack.c

clean:
	rm -f proj06 *.o
