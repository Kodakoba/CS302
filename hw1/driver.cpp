//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//DRIVER.CPP - drives the program, and makes you wanna have an anurism with the stuff that didn't make the final cut.
//all this SHOULD do is do the fun parts of the program.

#define MAX_ARRAY_SIZE 40 //a sneaky little macro for ez array management 

#include "bus.h"
#include "train.h"
#include "person.h"
#include "cargo.h"
#include <fstream> //for managing user input
#include <iostream>

using namespace std;

int readTextDataCargo(Cargo[], string); //was intended for testing
int readTextDataPeople(Person[], string);

int main(int argc, char* argv[]){
    
    if(argc < 2){ // Check File Input
        cout << "Error. Requires file name as first argument." << endl;
        return 1;
    }
    else{
        fstream inFile; //inFile definition
        inFile.open(argv[1]);
        if(inFile.fail()){
            cout << "File not found." << std::endl;
            return 1;
        }
        inFile.close();
    }
    //body begins here    
    Cargo inCargoList[MAX_ARRAY_SIZE];
    Person inPersonList[MAX_ARRAY_SIZE];
    //int totalCargoLoaded = readTextDataCargo(inCargoList, argv[1]);
    //int totalPeopleLoaded = readTextDataPeople(inPersonList, argv[1]);
    //std::cout << inCargoList[2].getType() << std::endl; //debug
    //std::cout << inPersonList[1].getName() << std::endl; //debug

    //Train construction!!!
    Train<Cargo> pacificFreight("Shasta");
    std::cout << "Pacific Freight train 101 is at " << pacificFreight.getDestination() << " ready to go loaded with the following: " << std::endl; 
    /*for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        pacificFreight.addItem(inCargoList[i]);
    }*/
    Cargo couch("couch", 120.0);
    Cargo rug("rug", 20.12);
    pacificFreight.addItem(couch);
    pacificFreight.addItem(rug);
    pacificFreight.displayNextStationAfterSend(); //looking back i poorly named this funcion, oopsie.
    std::cout << "the total weight is: " << pacificFreight.getWeight() << "kg." << std::endl;
    pacificFreight.moveFunc("Reno");
    std::cout << "Departure to " << pacificFreight.getDestination() << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Adding some stuff..." << std::endl;
    Cargo beer("lumber", 200.0);
    Cargo flowas("flowas", 14.598712293); //trolley
    pacificFreight.addItem(beer);
    pacificFreight.addItem(flowas);
    pacificFreight.removeItem(inCargoList[2]); //if this works i'll be damned.
    std::cout << "Pacific Freight train 101 is at " << pacificFreight.getDestination() << " ready to go loaded with the following: " << std::endl; 
    pacificFreight.displayNextStationAfterSend(); //woow
    std::cout << "the total weight is: " << pacificFreight.getWeight() << "kg." << std::endl;
    pacificFreight.moveFunc("Coeur D'Alene");
    std::cout << "Departure to " << pacificFreight.getDestination() << std::endl;
    std::cout << "-----------------" << std::endl;
    //BUS construction.
    Bus<Person> greyHound("San Diego", 20); //this is just rank bruh im sorry lol
    std::cout << "Greyhound 2237 is ready to load and depart to it's next stop. You are currently in " << greyHound.getDestination() << " ." << std::endl;
    /*for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        greyHound.addItem(inPersonList[i]);
    }*/
    Person ben("Ben", 177);
    Person rex("Rex", 200);
    greyHound.addItem(ben);
    greyHound.addItem(rex);
    greyHound.displayNextStationAfterSend();
    std::cout << "Loaded people, the fare totals for this trip are: " << greyHound.getTotal() << " at " << greyHound.getFare() << " per ticket." << std::endl;
    greyHound.moveFunc("Oakland");
    std::cout << "Departure to " << greyHound.getDestination() << "." <<std::endl;
    std::cout << "-----------------" << std::endl; // watch i make this a function and i get killed mysteriously (did this in 11th grade lol)
    std::cout << "Greyhound 2237 is ready to load and depart to it's next stop. You are currently in " << greyHound.getDestination() << " ." << std::endl;
    Person bento("Bento", 187.3);
    greyHound.addItem(bento); //i would remove someone too but i don't have time.
    greyHound.displayNextStationAfterSend();
    greyHound.setFare(10);
    std::cout << "Loaded people, the fare totals for this trip are: " << greyHound.getTotal() << " at " << greyHound.getFare() << " per ticket." << std::endl;
    greyHound.moveFunc("Sacramento");
    std::cout << "Departure to " << greyHound.getDestination() << "." <<std::endl;
    std::cout << "-----------------" << std::endl;
    
    //now our folks get on a TRAIN no way
    Train<Person> amtrak("Sacramento");
    std::cout << "Amtrak train 42 is at " << amtrak.getDestination() << " ready to go loaded with the following: " << std::endl;
    /*for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        amtrak.addItem(inPersonList[i]);
    }*/
    amtrak.addItem(ben);
    amtrak.addItem(rex);
    amtrak.addItem(bento);
    amtrak.displayNextStationAfterSend();
    amtrak.moveFunc("Reno");
    std::cout << "Departure to " << amtrak.getDestination() << std::endl;
    std::cout << "-----------------" << std::endl;
    /* THIS DIDN'T END UP WORKING I THINK BECAUSE OF THE HEIGHT ORDER FUNCTION. OH WELL. ITS 11PM AND ITS DUE IN AN HOUR. :c
    //lastly bus of cargo? a semi truck?
    Bus<Cargo> freightliner("Coeur D'Alene", 10);
    std::cout << "Freightliner Truck 2671 departing " << freightliner.getDestination() << "soon." << std::endl;
    /*for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        freightliner.addItem(inCargoList[i]);
    }*//*
    freightliner.addItem(couch);
    freightliner.addItem(rug);
    freightliner.addItem(beer); // im soon int age* = &21 :)
    freightliner.addItem(flowas); //i intentionally spelt it this way.
    freightliner.displayNextStationAfterSend();
    freightliner.moveFunc("Washington DC");
    std::cout << "Departure to " << freightliner.getDestination() << std::endl;
    std::cout << "-----------------" << std::endl;
    //clean up time :>
    freightliner.destroyEverything();*/
    amtrak.destroyEverything();
    pacificFreight.destroyEverything();
    greyHound.destroyEverything();
    
    return 0;
}

int readTextDataCargo(Cargo cargo[], string fileName){

    int quantity = 0; //assumes you have amount 0 for default amount in case it's not necessary to push. 
    double weight; 
    string type;
    string name;

    int index = 0; //start at top of file

    ifstream inFile(fileName.c_str()); //i still don't fully understand this. why is i/o a STRING?
    if(!inFile){  // Some file issue
        std::cout << "File not found." << std::endl;
        return index; // 0 means something went wrong
    }
    else{
        while(!(inFile.eof()) && index < MAX_ARRAY_SIZE){   //while not end of file and not exceeding our hard limit of people OR cargo.
            inFile >> type;
            //cout << "got to type " << type << " line 63" << endl; //debug message
            if(type == "cargo"){
                inFile >> type  >> name >> weight;
                if(inFile){//some really crazy safegaurd;
                    cargo[index].setWeight(weight);
                    cargo[index].setType(name);
                    cout << "got to cargo " << endl; //debug message
                    index++;
                }
            }
            else{
                //there should be a debug message here but it breaks sooooo oh well.
            }
        }
        
    } 
    return index;
}

int readTextDataPeople(Person person[], string fileName){
    
    int quantity = 0; //assumes you have amount 0 for default amount in case it's not necessary to push. 
    int height; // for people exclusively
    double weight; 
    string type;
    string name;

    int index = 0; //start at top of file

    ifstream inFile(fileName.c_str()); //i still don't fully understand this. why is i/o a STRING?
    if(!inFile){  // Some file issue
        cout << "File not found." << std::endl;
        return index; // 0 means something went wrong
    }
    else{
        while(!(inFile.eof()) && index < MAX_ARRAY_SIZE){
            inFile >> type;
            //cout << "got to type " << type << " line 102" << endl; //debug message
            if(type == "person" || type == "Person"){
                inFile >> type >> height >> name;
                if(inFile){//there's gotta be a better way to do this lol
                    person[index].setHeight(height);
                    person[index].setName(name);
                    cout << "got to people " << endl; //debug
                    index++;
                }
            }
            else{
                //std::cout << "No people were specified, moving forward..." << std::endl; //technically debug
                //why don't you wanna work bruh
            }
        }

    }
    return index;
}