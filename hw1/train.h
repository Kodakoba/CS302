//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//TRAIN.H - a type of transporter! we're a templeted class, and we do something funny: amongus sus out the weight of everything 
//(this was a bad joke im sorry)
#ifndef TRAIN_H
#define TRAIN_H

#include "transporter.h"
#include <vector> //YOU, you are back :)
#include <string> //safety
#include <algorithm> //i don't wanna make this.
#include <iostream> //don't kill me kthxbye

template<typename Item>
class Train : public Transporter<Item>{

    std::vector<Item> cargoList; //the only suitable way to do this. I'm using the c++ book from class to implement this so forgive me if i actually butcher this badly.
    std::string destination; //you're only allowed 5 stops per train.

public:
    Train() = default; //default train, apparently ""= default" is a cheezy easy way to do it too...
    //default destination constructor
    Train(const std::string &newDestination);
    //the full constructor
    Train(std::vector<Item> &newCargoList, std::string &newDestination); //so i had to look this up, apparently (&item2) is the reference equivilent to a vector?
    //friend mentioned you absolutely need to have a seperate one here for JUST THE LIST. it makes sense though! 
    Train(std::vector<Item> &newCargoList);
    //adds a something to an implemented list handler (in this case, our train).
    void addItem(const Item &itemA) override;
    //removes something from that list if defined.
    void removeItem(const Item &itemA) override;
    //move an item in the list if defined explicitly.
    //void moveItem(const T &itemA, int pos1, int pos2) override;
    std::string moveFunc(const std::string &destination2) override;
    //destroy everything :) (trust me its funny)
    void destroyEverything() override;
    //lets report the player who called the last function (list everything the object::transporter has.)
    int listItem() const override;
    //idk what this is even for.
    bool isEmpty() const override;
    //does the override keyword actually do anything?
    //this should technically be a function to get our weight and display it?
    double getWeight() const;
    //displays its destination (i'm also assuming people ride for free.)
    void displayNextStationAfterSend(); //print function W

    std::string getDestination() const; //apparently const is like, the c++ equivilent of "immutable"

    ~Train(){}; //deconstruct the train
};

#include "train.cpp"
//end of header
#endif