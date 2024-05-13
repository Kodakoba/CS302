#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"

template<class ItemType>
class BinarySearchTree: public BinaryTree<ItemType>{
    LinkedTreeNode<ItemType>* rootPtr;
public:
    BinarySearchTree();
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const; 
    ItemType getRootData() const override; //needs override to compile?
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    void preOrderTraverse(void visit(ItemType)) const;
    void inOrderTraverse(void visit(ItemType)) const;
    void postOrderTraverse(void visit(ItemType)) const;
    ~BinarySearchTree();
protected:
    LinkedTreeNode<ItemType>* placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
    LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, ItemType targetItem, bool& success);
    LinkedTreeNode<ItemType>* removeNode(LinkedTreeNode<ItemType>* nodePtr);
    LinkedTreeNode<ItemType>* removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType successor);
    LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* subTreePtr,const ItemType& targetItem) const;
    //fixed camelcasing :)
    void preOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const;
    void inOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const;
    void postOrder(void visit(ItemType), LinkedTreeNode<ItemType>* subTreePtr) const;
};

#include "binarysearchtree.cpp"
#endif