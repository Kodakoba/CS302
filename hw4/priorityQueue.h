//PRIORITYQUEUE.H - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//Implementation of an arrayQueue with additional attribute of priority and dealing with higher priorities.

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "arrayQueue.h"
#include <string> //might fix a runtime error

template<class ItemType>
class PriorityQueue: public ArrayQueue<ItemType>{
    int priority;
    public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    //basic add remove override?
    bool enqueue(const ItemType& newItem);
    bool dequeue();
    bool add(const ItemType& newEntry);
    bool remove();
    //destroy!
    ~PriorityQueue(){}
};




#include "priorityQueue.cpp"
#endif