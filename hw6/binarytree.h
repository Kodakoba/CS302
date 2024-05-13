#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "tree.h"
#include "linkedtreenode.h"

template<class ItemType> 
class BinaryTree: public TreeInterface<ItemType>{
private:
    LinkedTreeNode<ItemType>* rootPtr;
public:
    BinaryTree();
    BinaryTree(const BinaryTree& old);
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const; 
    ItemType getRootData() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    ~BinaryTree();

protected:
    int getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const;
    int getNumberNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const;
    LinkedTreeNode<ItemType>* copyHelper(LinkedTreeNode<ItemType>* subTreePtr2);
    LinkedTreeNode<ItemType>* balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
    LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType targetItem, bool& success);
    LinkedTreeNode<ItemType>* moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr);
    LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* subTreePtr, const ItemType& targetItem, bool& success) const;
    void burnTree(LinkedTreeNode<ItemType>* subTreePtr); //destroyTree is the actual name but burning it sounds funnier
};

#include "binarytree.cpp"
#endif
