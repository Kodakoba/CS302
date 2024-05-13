//LINKEDLIST.CPP - a collab between provided code and Lloyd Cargo (me)
//HW2 - Linked Lists vs Array List
//Implements the node based form of a list, I primarily had to implement the insert and default constructor/destructor. O(n).
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){ //no YOU are the copy constructor
    this->headPtr = nullptr;
	itemCount = 0;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    //so we need to get the where we are, where you were, and where you're going. - BTTF
	if (newPosition == 1){
		//in the case it's the first node
		Node<ItemType>* nPtr = new Node<ItemType>(newEntry, nullptr); 
		nPtr->setNext(headPtr); //in this particular case we need to tell the head pointer "we are number one"
		headPtr = nPtr;
		itemCount++;
		return true;
	}
	else{
		Node<ItemType>* beforePtr = getNodeAt(newPosition - 1); //for the one before (currently occupied)
		Node<ItemType>* afterPtr = getNodeAt(newPosition); //for the one in front
		Node<ItemType>* nPtr = new Node<ItemType>(newEntry, afterPtr); // probably not right
		nPtr->setNext(beforePtr->getNext());
		beforePtr->setNext(nPtr);
		//should be shrimple :)
		itemCount++;
		return true;
	}

    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear(){ //no no no YOU are the destructor.
    for(int i = itemCount; i > 0 ; i--){
		remove(i); //cheesy :>
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
	Node<ItemType>* nodePtr = getNodeAt(position);
	ItemType temp = nodePtr->getItem();
    return temp;
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
