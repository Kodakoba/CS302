//LINKEDLIST.H - By Lloyd Cargo
//HW3 - Staks
//definition of our node based stack, from stack.h
#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template<class ItemType>
class LinkedStack: public StackInterface<ItemType> {
private:
    Node<ItemType>* topPtr;
    //from class - we don't need anything more! 
public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>&);
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    ~LinkedStack();
};

#include "linkedStack.cpp"
#endif