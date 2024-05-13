//DRIVER.CPP - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//Implements the datastructures with infile provided. EVENTS MAY BE HANDLED HERE.
#include "arrayQueue.h"
#include "priorityQueue.h"
#include "person.h"
#include "event.h"
#include <iostream>
#include <fstream>
#include <sstream>
//that's a lot of includes.

//functions all return a boolean solely to help with error testing later.
bool processArrival();
bool processDeparture();
bool processEvent();

int main(int argc, char* argv[]){
    if(argc < 2){ // Check File Input
        std::cout << "Error. Requires file name as first argument." << std::endl;
        return 1;
    }

    std::fstream inFile; //inFile definition
    inFile.open(argv[1]);
    if(inFile.fail()){
        std::cout << "File not found." << std::endl;
        return 1;
    }
    ArrayQueue<Person> bankQueue;
    PriorityQueue<Event> eventQueue;
    Person Customers;
    std::string inputs;
    int time =0, transaction =0, numPeople = 0, waitTime = 0, currentTime = 0;
    bool tellerAvailable = true;
    int WaitTime = 0;
    std::cout<<"Simulation Begins"<<std::endl;
    //input from file
    while(getline(inFile,inputs)){
        std::string newArrivalEvent = inputs;
        /*std::istringstream separate(newArrivalEvent);
        separate >> time;
        separate >> transaction;*/
        inFile >> time >> transaction;
        Event arrival(time, transaction, "Arrival");
        eventQueue.enqueue(arrival); //as a fall back
        eventQueue.add(arrival);
    }
    inFile.close();
    //driver begins here
    while(!eventQueue.isEmpty())
    {//B
        std::cout<<"got to 51"<<std::endl;
        Event newEvent = eventQueue.peekFront(); //<- you are throwing an error
        std::cout<<"got to 53"<<std::endl;
        currentTime = newEvent.time; //<- you might but it's unlikely.
        std::cout<<"got to 54"<<std::endl;
        if(newEvent.Type == "Arrival")
        {//A
            std::cout << "Processing an arrival event at time: " << newEvent.time << std::endl;
            eventQueue.remove();
            std::cout<<"got to 58"<<std::endl;
            if(bankQueue.isEmpty() && tellerAvailable)
            {//C

                int departureTime = currentTime + newEvent.transaction;
                Event newDepartureEvent(departureTime, 0, "Departure");
                eventQueue.add(newDepartureEvent);
                tellerAvailable =  false;

            }//end of C
            else{
                bankQueue.enqueue(Person(newEvent.time, newEvent.transaction));
            }
        }//end of A
        else{//E
            std::cout << "Processing a departure event at time: " << newEvent.time << std::endl;
            numPeople++;
            eventQueue.remove();
            if(!bankQueue.isEmpty())
            {
                Customers = bankQueue.peekFront();
                bankQueue.dequeue();
                waitTime += currentTime - Customers.getArrivalTime();
                int departureTime = currentTime + newEvent.transaction;
                Event newDepartureEvent(departureTime, 0, "Departure");
                eventQueue.add(newDepartureEvent);
            }
            else
            {
                tellerAvailable = true;
            }
        }//end of E

    }//end of B
    return 0;
}

bool processArrival(){
    return true;
}

bool processDeparture(){
    return true;
}
bool processEvent(){
    return true;
}