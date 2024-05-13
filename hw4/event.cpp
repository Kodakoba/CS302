//EVENT.CPP - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//THIS MAY NOT BE USED! - depends on if it is worthwhile to turn this into a "struct" or class.
//Handles events based on arrival and dequeuing.
#include "event.h"

Event::Event(){
    time = 0;
    transaction = 0;
    Type = " ";
}

Event::Event(int newTime, int newTransaction, std::string newType){
    time = newTime;
    transaction = newTransaction;
    Type = newType;
}
/*
int Event::getTime(){
    return time;
}

int Event::getTransaction(){
    return transaction;
}

std::string Event::getType(){
    return Type;
}

void Event::setTime(int nTime){
    time = nTime;
}

void Event::setTransaction(int nTrans){
    transaction = nTrans;
}

void Event::setType(std::string nType){
    Type = nType;
}
*/
bool Event::operator<(const Event& rhs)const{
    return time < rhs.time;
}