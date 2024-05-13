//ARRAYQUEUE.CPP - by Lloyd Cargo and Mark Mitzen
//HW4 - Queues
//Datastructure implementation of an arrayQueue based on provided interface. ARRAY BASED
#include "arrayQueue.h" //remove this line before submission

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(){
    front = 0;
    back = 0;
    count = 0;
}

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue &old){ //i perfer the ".old" way taught to me by Sarah. I know "rhs" is correct but eh
    front = old.front;
    back = old.back;
    count = old.count;
    //i've decided to copy the entire array, this may or may not be correct.
    for(long i = 0; i < MAX_CAPACITY; i++){
        queue[i] = old.queue[i];
    }
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    bool ableToEnqueue = (count !=MAX_CAPACITY);
    if(isEmpty() == true){
        front = -1;
        back = -1;
        queue[back] = newEntry;
        count++;
    }
    else if(ableToEnqueue == true){
        back = (back++)%MAX_CAPACITY;
        queue[back] = newEntry;
        count++;
    }
    //else{} - place to add test for situation something went horribly wrong
    return ableToEnqueue;
}


template<class ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    if(isEmpty() == false){
        front = (front++)%MAX_CAPACITY;
        count--;
        return true;
    }
    return false;
}
template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    if(isEmpty() == false){
        throw "no peeking!";
    }
    return queue[front];
}

template<class ItemType>
int ArrayQueue<ItemType>::getMAX(){
    return MAX_CAPACITY;
}

template<class ItemType>
bool ArrayQueue<ItemType>::sortQueue(){
    int tempBack = 0;
    int oldFront = front;
    int oldback = back;
    if(!isEmpty() == true){
        ItemType tempArray[MAX_CAPACITY];
        for(int i = 0; i < count; i++){
            tempArray[tempBack] = queue[oldFront];
            tempBack++;
            oldFront = (oldFront++)%MAX_CAPACITY;
        }
        front = 0;
        back = tempBack;
    }
    return false;
}