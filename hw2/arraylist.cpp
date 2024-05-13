//ARRAYLIST.CPP - a collab between provided code and Lloyd Cargo (me)
//HW2 - Linked Lists vs Array List
//Implements the array form of a list, I primarily had to implement the remove and default constructor. O(1).
template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	//copy constructor
	itemCount = 0;
	for(int i = 0; i < DEFAULT_CAPACITY; i++){
		items[i] = items.aList[i];
	}
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	//if array == 0 return true
	bool isEmpty = (itemCount == 0);
	return isEmpty;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1) &&
                            (itemCount < maxCount);
	if (ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
			items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
        	itemCount++;
    	}
    	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	//same as insert but in reverse with an if array[position] == empty, return a statement saying you can't
	bool ableToRem = (position >= 1) && (position <= itemCount);

	if (ableToRem){
		for(int i = itemCount + 1; i < DEFAULT_CAPACITY; i++){
			items[i] = items[i + 1];
			itemCount --;
		}
		return true;
	} 

    return false;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
    	bool ableToGet = (position >= 1) && (position <= itemCount);
		ItemType temp;
		if (ableToGet){
			temp = items[position];
			items[position] = newEntry;
		} 
    	return temp;
}
