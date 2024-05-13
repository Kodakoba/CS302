#sudo make me a sandwich
traveler: driver.o
	g++ -o traveler driver.o

driver.o: driver.cpp arrayGraph.h arrayQueue.h
	g++ -c driver.cpp

clean:
	rm *.o traveler