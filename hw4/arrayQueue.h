//ARRAYQUEUE.H - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//Datastructure implementation of an arrayQueue based on provided interface.
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "queue.h"
//#define MAX_CAPACITY 100 //some arbitrary "large" number.

template<class ItemType>
class ArrayQueue: public QueueInterface<ItemType>{
protected:
    static const int MAX_CAPACITY = 100;
    ItemType queue[MAX_CAPACITY];
    int front, back, count;

public:
    ArrayQueue();
    ArrayQueue(const ArrayQueue&);
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    int getMAX(); //returns MAX_CAPACITY macro 
    //default deconstructor
    ~ArrayQueue(){} 

protected:
    bool sortQueue(); //all you do is move everything to 0, in case this becomes easier to implement.
    //remind me to remove these two lines if we do it some other way.
};

#include "arrayQueue.cpp"
#endif