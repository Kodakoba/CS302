//PERSON.H - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//The person object. Will require OP overloading to do "sorting" by priority.
#ifndef PERSON_H
#define PERSON_H

#include<iostream> //for ostream

class Person{
    int timeArrived;
    int transactionLength;

    public:
    Person() = default;
    Person(int,int);
    Person(const Person&);

    int getArrivalTime();
    int getTransLen();

    void setArrivalTime(int);
    void setTransLen(int);

    //operator overload goes here, i think:
    friend bool operator>(const Person& lhs,const Person &rhs);
    //i have no clue if this is needed, but I *think* it is?
    //friend std::ostream &operator<<(std::ostream &out, const Person &rhs);

    ~Person() {}
};


#endif