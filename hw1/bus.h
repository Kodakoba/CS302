//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//BUS.H - a type of transporter! we're a templeted class, and we do something funny: sorting function people simulator
#ifndef BUS_H
#define BUS_H

#include "transporter.h" //include our interface
#include <string> //for displaying our places
#include <iostream> //used in implementation
#include <vector> // from train.h
#include <algorithm> //for sorting

template<typename Item>
class Bus: public Transporter<Item> {

    std::vector<Item> peopleList; //in theory an array of our templated class objects
    std::string destination; //you're only allowed 5 stops per train.
    int fareprice;

public:
    //default constructor
    Bus() = default;
    //destination constructor
    Bus(const std::string &newDestination);
    //destination and fee
    Bus(const std::string &newDestination, const int &farePrice2);
    //now adding people (or cargo if you're mean)
    Bus(std::vector<Item> &newPeopleList);
    //adds the previous and a destination
    Bus(std::vector<Item> &newPeopleList, const std::string &newDestination);
    //last case for all the above. TLDR is you account for all cases.
    Bus(std::vector<Item> &newPeopleList, const std::string &newDestination, const double &farePrice2);
    //overriden template interface stuff, apparently **this** is how you access them...
    void addItem(const Item &itemA) override;
    //and to remove something
    void removeItem(const Item &itemA) override;
    //not entirely sure why i made this function not gonna lie to you.
    //void moveItem(const Item &itemA, int pos1, int pos2);
    //this makes so much more sense than my other implementation of this, i'm going to remove it before submission.
    std::string moveFunc(const std::string &destination2) override; //copied from train lol
    //destroy everything :) (trust me its funny)
    void destroyEverything() override;
    //lets report the player who called the last function (list everything the object::transporter has.)
    int listItem() const override; //amount of people on this bus.
    //idk what this is even for.
    bool isEmpty() const override;
    //displays everyone's height
    void setFare(const int &farePrice2);
    //getter
    int getFare();
    //all togetter (ok that was a bad dad joke im sorry)
    int getTotal();
    //next destination
    std::string getDestination() const;
    //display
    void displayNextStationAfterSend(); 
};

#include "bus.cpp"
#endif