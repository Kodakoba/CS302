//LINKEDLIST.CPP - By Lloyd Cargo
//HW3 - Staks
//implementation of our node based stack, from stack.h (a little cursed)
template <class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr){}

template <class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType> &old){ 
    topPtr = nullptr;
    Node<ItemType>* copyPtr = old.topPtr;
    Node<ItemType>* stackPtr = nullptr;
    while(copyPtr != nullptr){
        Node<ItemType>* nPtr = new Node<ItemType>(copyPtr->getItem());
        if(topPtr == nullptr){
            topPtr = nPtr; //weird instance you decided to copy nothing (empty stack)?
        }
        else{
            stackPtr->setNext(nPtr);
        }
        stackPtr = nPtr;
        copyPtr = copyPtr->getNext();
    }
}

template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return topPtr == nullptr; //technically compacts the if/else part to 1 line
}

template <class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    Node<ItemType>* nPtr = new Node<ItemType>(newEntry);
    //technically this should always be true? cause the stack is "never full" unless something has gone horribly horribly wrong
    //looking back technically:
    if(nPtr == nullptr){
        throw "something went horribly wrong allocating the node";
        return false;
    } 
    //should be here but idk
    nPtr->setNext(topPtr);
    topPtr = nPtr;
    return true;
}

template <class ItemType>
bool LinkedStack<ItemType>::pop(){
    //it's like LL::remove, but easier;
    bool ableToRemove = (topPtr != nullptr);
    if(ableToRemove == true){
        Node<ItemType>* tempPtr = topPtr;
        topPtr = topPtr->getNext();
        delete tempPtr;
        return true;
    }
    return false;
}

template <class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    bool ableToPeek = (topPtr != nullptr);
    if(ableToPeek){
        return topPtr->getItem();
    }
    throw "invalid position or stack is empty";
    //i guess you *technically* can't return an item and a bool.
}

template <class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    for(Node<ItemType>* tempPtr = topPtr; tempPtr != nullptr;){ //holy wow is this cursed
        Node<ItemType>* tempNPtr = tempPtr->getNext();
        delete tempPtr;
        tempPtr = tempNPtr; 
    }
    //topPtr = topPtr->setNext(nullptr); //loud incorrect buzzer
    topPtr = nullptr;
}