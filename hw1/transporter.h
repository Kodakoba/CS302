//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//TRANSPORTER.H - INTERFACE PRACTICE - an interface for things that move!
//all functions must be purely virtual and self explainatory.
#ifndef TRANSPORTER_H
#define TRANSPORTER_H

#include <string>

template<typename Item>
class Transporter{
    //public defs should be add an item, remove an item, delete all, and move. items should report what is there.
public:
//constructors anyone?
    //adds a something to an implemented list handler.
    virtual void addItem(const Item &item) = 0;
    //removes something from that list if defined.
    virtual void removeItem(const Item &item) = 0;
    //destroy everything :) (trust me its funny)
    virtual void destroyEverything() = 0;
    //all transports have some implementation of this stuff
    virtual int listItem() const = 0;
    //how to go to next train ride irl
    virtual std::string moveFunc(const std::string &nextDestination) = 0;
    //emptyWhen
    virtual bool isEmpty() const = 0;
};

#endif
