//PRIORITYQUEUE.CPP - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//Implementation of an arrayQueue with additional attribute of priority and dealing with higher priorities.
#include "priorityQueue.h" //remove this line before submission

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(){
    this->front = -1;
    this->back = -1;
    this->count = 0;
    priority = 0;
}

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue &old){
    this->front = old.front;
    this->back = old.back;
    this->count = old.count;
    priority = old.priority;
    for(int i = 0; i < this->MAX_CAPACITY; i++){ //this feels cursed or redundant 
        this->queue[i] = this->old.queue[i];
    }
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newItem){
    if (this->count == this->MAX_CAPACITY) {
        return false;
    }
    else if (this->front == -1) {
        this->front = this->back = 0;
        this->queue[0] = newItem;
        this->count++;

    }
    else if (this->back == this->MAX_CAPACITY -1 && this->front != 0) {
        this->back = 0;
        this->queue[this->back] = newItem;
        this->count++;
    }
    else {
        this->back++;
        this->queue[this->back] = newItem;
        this->count++;
    }
    return true;
}

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue(){
    //I THINK you have to be re-instantiated. i don't know man, im just a dog. 
    if(this->isEmpty() == false){
        this->front = (this->front++)%this->MAX_CAPACITY;
        this->count--;
        return true;
    }
    return false;
}

template<class ItemType>
bool PriorityQueue<ItemType>::add(const ItemType &newEntry) {
    //this is a big question to tackle, so i'm imagining we need to test if its Q able, if its empty, then use some overload of person to "sort" the person by priority.
    //originally I assumed the **whole queue** would have the same priority, but we shall see.
    bool ableToEnqueue = (this->count !=this->MAX_CAPACITY); //the this-> keyword is getting mildly annoying now.
    if(this->isEmpty() && ableToEnqueue == true){
        this->front++;
        this->back++; //can i combine all of you onto one line?
        this->count++;
        this->queue[this->back] = newEntry;
        //priority = 1; //do we need to get this from person()?
        return true;
    }
    else if(!this->isEmpty() && ableToEnqueue == true){
        //so i need to *insert* it based on some thing, i think < needs to be overloaded.
        int temp = -1;
        for(int i = this->front; i < this->back; i++){
            if(newEntry < this->queue[i]){
                temp = i;
                break; //i hope to god this doesn't actually exit the function
            }
        }
        //now we need to handle case index is still -1, and the situation the capacity is reached from arrayList
        if(temp == -1){
            this->back = (this->back++)%this->MAX_CAPACITY;
            this->queue[this->back] = newEntry;
        }
        else{
            for(int k = this->back; k>=temp;k--){ //operator overload trolley
                this->queue[k++] = this->queue[k];
            }
            this->queue[this->back] = newEntry;
            this->back = (this->back++)%this->MAX_CAPACITY;
        }
        this->count++;
    }
    else{
        throw "priority queue had a queue exception";
    }
    return ableToEnqueue;
}

template<class ItemType>
bool PriorityQueue<ItemType>::remove() {
    return dequeue();
}