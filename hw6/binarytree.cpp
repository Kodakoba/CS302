#include "binarytree.h"
#include <algorithm>

template<class ItemType> 
BinaryTree<ItemType>::BinaryTree():rootPtr(nullptr) {}

template<class ItemType> 
BinaryTree<ItemType>::BinaryTree(const BinaryTree& old){
    if(old.rootPtr == nullptr){ //base case
        rootPtr == nullptr;
    }
    else{
        rootPtr = new LinkedTreeNode<ItemType>(old.rootPtr->getItem());
        rootPtr->setLeftChildPtr(copyHelper(old.rootPtr ->getLeftChildPtr()));
        rootPtr->setRightChildPtr(copyHelper(old.rootPtr ->getRightChildPtr()));
    }
}

template<class ItemType> 
bool BinaryTree<ItemType>::isEmpty() const{
    return getHeightHelper(rootPtr);
}

template<class ItemType> 
int BinaryTree<ItemType>::getHeight() const{
    return getHeightHelper(rootPtr);
}

template<class ItemType> 
int BinaryTree<ItemType>::getNumberOfNodes() const{
    return getNumberNodesHelper(rootPtr);
} 

template<class ItemType> 
ItemType BinaryTree<ItemType>::getRootData() const{
    return rootPtr->getItem();
}

template<class ItemType> 
bool BinaryTree<ItemType>::add(const ItemType& newEntry){
    LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>(newEntry);
    newNode->setItem(newEntry);
    newNode->setLeftChildPtr(nullptr);
    newNode->setRightChildPtr(nullptr);
    rootPtr = balancedAdd(rootPtr, newNode);
    return true;
}

template<class ItemType> 
bool BinaryTree<ItemType>::remove(const ItemType& anEntry){
    bool endResult = 0;
    endResult = removeValue(rootPtr, anEntry, endResult);
    return endResult;
}

template<class ItemType> 
void BinaryTree<ItemType>::clear(){
    if(isEmpty() == true){
        return;
    }
    else{
        burnTree(rootPtr);
        rootPtr = nullptr;
    }
}

template<class ItemType> 
bool BinaryTree<ItemType>::contains(const ItemType& anEntry) const{
    bool endResult = 0;
    findNode(rootPtr, anEntry, endResult);
    return endResult;
}

template<class ItemType> 
int BinaryTree<ItemType>::getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr == nullptr){ //if its the root, its 0, otherwise it is 1 + subtree
        return 0;
    }
    else{
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class ItemType> 
int BinaryTree<ItemType>::getNumberNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const{
    if(subTreePtr == nullptr){ //if its the root, its 0, otherwise it is 1 + subtree
        return 0;
    }
    else{
        return 1 + getHeightHelper(subTreePtr->getLeftChildPtr()) + getHeightHelper(subTreePtr->getRightChildPtr()); //does not need max, just add
    }
}

template<class ItemType> 
LinkedTreeNode<ItemType>* BinaryTree<ItemType>::copyHelper(LinkedTreeNode<ItemType>* subTreePtr2){
    if(subTreePtr2 == nullptr){ //base
        return nullptr;
    }
    else{
        LinkedTreeNode<ItemType>* newNode = new LinkedTreeNode<ItemType>(subTreePtr2->getItem());
        newNode->setLeftChildPtr(copyHelper(subTreePtr2->getLeftChildPtr()));
        newNode->setRightChildPtr(copyHelper(subTreePtr2->getRightChildPtr()));
        return newNode;
    }
}

template<class ItemType> 
LinkedTreeNode<ItemType>* BinaryTree<ItemType>::balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr){
    if(subTreePtr == nullptr){ //base
        return newNodePtr;
    }
    else{
        if(getHeightHelper(subTreePtr ->getLeftChildPtr()) > getHeightHelper(subTreePtr-> getRightChildPtr())){ //if A > B
            subTreePtr->setRightChildPtr(balancedAdd(subTreePtr ->getRightChildPtr(), newNodePtr));
        }
        else{ // A < B
            subTreePtr->setLeftChildPtr(balancedAdd(subTreePtr ->getLeftChildPtr(), newNodePtr));
        }
    }
    return subTreePtr;
}

template<class ItemType> 
LinkedTreeNode<ItemType>* BinaryTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType targetItem, bool& success){
    if(subTreePtr == nullptr){ //base
        success = false;
        return subTreePtr;
    }
    else if(subTreePtr->getItem() == targetItem){
        success = true;
        if(subTreePtr->isLeaf() == true){ //case it is a leaf to deallocate
            delete subTreePtr;
            subTreePtr = nullptr;
            return subTreePtr;
        }
        else{ //and if it isn't
            subTreePtr = this->moveValuesUpTree(subTreePtr);
            return subTreePtr;
        }
    }
    else{ //isn't base nor a leaf, first left then right
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr ->getLeftChildPtr(),targetItem,success));
        if(success == false){
            subTreePtr->setRightChildPtr(removeValue(subTreePtr ->getRightChildPtr(),targetItem,success));
        }
        return subTreePtr;
    }
}

template<class ItemType> 
LinkedTreeNode<ItemType>* BinaryTree<ItemType>::moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr){
    if(subTreePtr == nullptr){ //base
        return subTreePtr;
    }
    LinkedTreeNode<ItemType>* curPtr = subTreePtr->getRightChildPtr(); //keeping track while moving right to left to read the whole tree from the leaves?
    while(curPtr != nullptr){ //for all curPtr != rootPtr
        if(curPtr->getLeftChildPtr() != nullptr){
            curPtr = curPtr->getLeftChildPtr();
        }
        else{
            break;
        }
    }
    subTreePtr ->setItem(curPtr ->getItem());
    bool success = false; //default success
    //rm -rf next node for new guy
    LinkedTreeNode<ItemType>* newRightChild = removeValue(subTreePtr ->getRightChildPtr(),curPtr ->getItem(),success);
    if(success == true){
        subTreePtr->setRightChildPtr(newRightChild);
    }
    return subTreePtr;
}

template<class ItemType> 
LinkedTreeNode<ItemType>* BinaryTree<ItemType>::findNode(LinkedTreeNode<ItemType>* subTreePtr, const ItemType& targetItem, bool& success) const{
    if(subTreePtr == nullptr){ //base
        success = false;
        return subTreePtr;
    }
    else if(subTreePtr->getItem() == targetItem){
        success = true;
        return subTreePtr;
    }
    else{
        return findNode(subTreePtr->getRightChildPtr(),targetItem,success);
        if(!subTreePtr){
            return findNode(subTreePtr->getLeftChildPtr(),targetItem,success);
        }
    }
}

template<class ItemType> 
void BinaryTree<ItemType>::burnTree(LinkedTreeNode<ItemType>* subTreePtr){ //destoyTree
    if(subTreePtr == nullptr){
        return;
    }
    else{
        burnTree(subTreePtr->getLeftChildPtr());
        burnTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }
}

template<class ItemType> 
BinaryTree<ItemType>::~BinaryTree(){
    clear();
}