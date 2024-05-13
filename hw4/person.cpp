//PERSON.CPP - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//The person object. Will require OP overloading to do "sorting" by priority.
#include "person.h"

Person::Person(int newTime,int newTrTm){
    timeArrived = newTime;
    transactionLength = newTrTm;
}

Person::Person(const Person &old){
    timeArrived = old.timeArrived;
    transactionLength = old.transactionLength;
}

int Person::getArrivalTime(){
    return timeArrived;
}
int Person::getTransLen(){
    return transactionLength;
}

void Person::setArrivalTime(int newTime){
    timeArrived = newTime;
}

void Person::setTransLen(int newTrLen){
    transactionLength = newTrLen;
}

bool operator>(const Person& lhs,const Person &rhs){
    return lhs.timeArrived > rhs.timeArrived;
}

/*std::ostream &operator<<(std::ostream &out, const Person &rhs){
    out << rhs.timeArrived;
    return out;
}*/