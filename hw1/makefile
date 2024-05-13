#Lloyd Cargo HW1 makefile. I'm as surprised as you to see a comment here.
#assembly
driver: driver.o cargo.o person.o train.h train.cpp bus.h bus.cpp 
	g++ -o transport driver.o cargo.o person.o 

driver.o: driver.cpp  
	g++ -c -o driver.o driver.cpp 

cargo.o: cargo.cpp cargo.h
	g++ -c cargo.cpp 

person.o: person.cpp person.h
	g++ -c person.cpp

#bus.o: transporter.h bus.h bus.cpp
#	g++ -c bus.cpp bus.h

#the infamous clean command
clean:
	rm *.o *.gch transport