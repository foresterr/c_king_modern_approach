queueclient: queueclient.o queueADT.o
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -o queueclient queueclient.o queueADT.o

queueclient.o: queueclient.c queueADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c queueclient.c

queueADT.o: queueADT.c queueADT.h
	gcc -O -Wall -Wextra -Wpedantic -std=c99 -c queueADT.c

clean:
	rm -f queueclient *.o
