#HW4 Queues by LC and MM
all: driver.o event.o person.o arrayQueue.h priorityQueue.h
	g++ driver.o event.o person.o -g -o bank_sim

driver.o: driver.cpp arrayQueue.h priorityQueue.h event.o person.o
	g++ -g -c driver.cpp

person.o: person.h person.cpp
	g++ -g -c person.cpp

event.o: event.h event.cpp 
	g++ -g -c event.cpp

clean:
	rm *.o bank_sim