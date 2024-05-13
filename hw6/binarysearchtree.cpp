#include "binarysearchtree.h"

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree():rootPtr(nullptr){}

template<class ItemType>
bool BinarySearchTree<ItemType>:: isEmpty() const{
    return rootPtr == nullptr;
}
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const{
    return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{
    return this->getNumberNodesHelper(rootPtr);
} 

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const{
    return rootPtr->getItem(); //wonder why it auto changes a "." to "->"
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry){
    LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>(newEntry);
    newNode->setItem(newEntry);
    newNode->setLeftChildPtr(nullptr);
    newNode->setRightChildPtr(nullptr);
    rootPtr = placeNode(rootPtr, newNode); //balanced add deluxe
    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry){
    bool success = 0;
    success = removeValue(rootPtr, anEntry, success);
    return success;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear(){
    if(isEmpty() == true){
        return;
    }
    else{
        this->burnTree(rootPtr);
        rootPtr = nullptr; //do you go outside the else statement
    }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const{
    LinkedTreeNode<ItemType>* item = findNode(rootPtr, anEntry);
    if(item != nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::preOrderTraverse(void visit(ItemType)) const{
    preOrder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inOrderTraverse(void visit(ItemType)) const{
    inOrder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postOrderTraverse(void visit(ItemType)) const{
    postOrder(visit, rootPtr);
}
//---
template<class ItemType>
LinkedTreeNode<ItemType>* BinarySearchTree<ItemType>::placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
    if(subTreePtr == nullptr){
        return newNodePtr;
    }
    else if(subTreePtr->getItem() < newNodePtr->getItem()){
        subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
    }
    else{
        subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
    }
    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* BinarySearchTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, ItemType targetItem, bool& success){
    if(subTreePtr == nullptr){
        success == false;
        return subTreePtr;
    }
    else if(subTreePtr->getItem() == targetItem){
        success == true;
        subTreePtr = removeNode(subTreePtr);
        return subTreePtr;
    }
    else{
        if(targetItem > subTreePtr->getItem()){
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(),targetItem,success));
        }
        else{
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), targetItem, success));
        }
        return subTreePtr;
    }
}

template<class ItemType>
LinkedTreeNode<ItemType>* BinarySearchTree<ItemType>::removeNode(LinkedTreeNode<ItemType>* nodePtr){
//triple case magic, case it has 2 children, a child, or it's a leaf of the tree. Leaf goes first.
    if(nodePtr->isLeaf() == true){
        delete nodePtr;
        nodePtr == nullptr;
    }
//case it is one child
    else if(nodePtr->getLeftChildPtr() && !nodePtr->getRightChildPtr()){
        LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>();
        newNode->setItem(nodePtr->getLeftChildPtr()->getItem());
        nodePtr->setLeftChildPtr(nullptr);
        delete nodePtr;
        nodePtr = nullptr; //for cleanup
        return newNode;
    }
    else if(nodePtr->getRightChildPtr() && !nodePtr->getLeftChildPtr()){
        LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>();
        newNode->setItem(nodePtr->getRightChildPtr()->getItem());
        nodePtr->setRightChildPtr(nullptr);
        delete nodePtr;
        nodePtr = nullptr; //for cleanup
        return newNode;
    }
//case it has two children (boo)
    else if(nodePtr->getLeftChildPtr() && nodePtr->getRightChildPtr()){
        LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>();
        newNode = removeLeftmostNode(nodePtr, nodePtr->getRightChildPtr()->getItem()); //according to many sources, this is when this is needed.
        delete nodePtr;
        nodePtr = nullptr;
        return newNode;
    }
//I contemplated an "else" case that raises an error but that's too much work.
    return nodePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType successor){
//in successor
    if(nodePtr->getLeftChildPtr() == nullptr){
        successor = nodePtr->getItem();
        if(nodePtr->getRightChildPtr() != nullptr){ //in case it's the right hand chance
            return nodePtr->getRightChildPtr();
        }
        return nodePtr;
    }
    else{
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), successor));
        return nodePtr;
    }
}

template<class ItemType>
LinkedTreeNode<ItemType>* BinarySearchTree<ItemType>::findNode(LinkedTreeNode<ItemType>* subTreePtr,const ItemType& targetItem) const{
    if(subTreePtr == nullptr){
        return subTreePtr;
    }
    else if(subTreePtr->getItem() == targetItem){
        return subTreePtr;
    }
    else if(targetItem < subTreePtr->getItem()){ //left case
        return findNode(subTreePtr->getLeftChildPtr(), targetItem);
    }
    else{ //right case
        return findNode(subTreePtr->getRightChildPtr(), targetItem);
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::preOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){
        visit(subTreePtr->getItem());
        preOrder(visit, subTreePtr->getLeftChildPtr());
        preOrder(visit, subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::inOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){
        inOrder(visit, subTreePtr->getLeftChildPtr());
        ItemType item = subTreePtr->getItem();
        visit(item);
        inOrder(visit, subTreePtr->getRightChildPtr());
        //originally added ItemType item2, and visit item2, but that is pointless. -L
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::postOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){ //!preOrder
        postOrder(visit, subTreePtr->getLeftChildPtr());
        postOrder(visit, subTreePtr->getRightChildPtr());
        visit(subTreePtr->getItem());
    }
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
    clear();
}