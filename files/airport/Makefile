CC=gcc
CFLAGS=-Wall -g

.PHONY: all

all: bin/airportDriver

bin/airportDriver: bin/airportDriver.o bin/airport.o
	${CC} ${CFLAGS} bin/airportDriver.o bin/airport.o -o bin/airportDriver
	
bin/airportDriver.o: src/airportDriver.c include/airport.h
	${CC} ${CFLAGS} -c src/airportDriver.c -o bin/airportDriver.o
	
bin/airport.o: src/airport.c include/airport.h ../DynamicList/include/list.h
	${CC} ${CFLAGS} -c src/airport.c -o bin/airport.o

../../DynamicQueue/bin/queue.o: ../../DynamicQueue/src/queue.c ../../DynamicQueue/include/queue.h ../../DynamicList/include/list.h
	cd ../DynamicQueue; make bin/queue.o
	
../../DynamicPriorityQ/bin/pQueue.o: ../../DynamicPriorityQ/src/pQueue.c ../../DynamicPriorityQ/include/pQueue.h ../../DynamicList/include/list.h
	cd ../DynamicPriorityQ; make bin/pQueue.o

../../DynamicList/bin/list.o: ../../DynamicList/src/list.c ../../DynamicList/include/list.h
	cd ../DynamicList; make bin/list.o

clean:
	rm bin/*
	
valgrind:
	valgrind -v --leak-check=yes bin/airportDriver
	
tarball:
	cd..; tar czf cs300_6B_rapa8846.tar.gz Airport DynamicQueue DynamicPriorityQ DynamicList