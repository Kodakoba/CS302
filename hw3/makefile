#makefile for HW3 staks by LC, this comment gets one line.
stackSim: driver.o 
	g++ driver.o -o stacksim

driver.o: driver.cpp linkedStack.h node.h
	g++ -g -c driver.cpp

clean:
	rm *.o stacksim