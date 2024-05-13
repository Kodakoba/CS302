//EVENT.H - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//THIS MAY NOT BE USED! - depends on if it is worthwhile to turn this into a "struct" or class.
//Handles events based on arrival and dequeuing.
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

class Event {
public:
    int time, transaction;
    std::string Type;

    bool operator<(const Event &rhs) const;
    Event();
    Event(int newTime, int newTransaction, std::string newType);

    /*int getTime();
    int getTransaction();
    std::string getType();

    void setTime(int);
    void setTransaction(int);
    void setType(std::string);*/

    ~Event() {};
};

#endif