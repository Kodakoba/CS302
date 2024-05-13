//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//the implementation of the train class and it's functions as defined by the header. oddly it's very finnicky despite being a pure clone of bus, and bus being a clone of train.
//no
#include "train.h"
//#include <iostream>
//case 1
template <typename Item>
Train<Item>::Train(const std::string &newDestination):destination(newDestination){}
//case 2
template <typename Item>
Train<Item>::Train(std::vector<Item> &newCargoList, std::string &newDestination):cargoList(newCargoList), destination(newDestination){}
//case 1 + 2
template<typename Item>
Train<Item>::Train(std::vector<Item> &newCargoList):cargoList(newCargoList){}

template <typename Item>
void Train<Item>::addItem(const Item& itemA){ 
    cargoList.push_back(itemA); //this makes me angry. I spent all this time making a loop and complicated array stuff just to have it right here.
}

//removes something from that list if defined.
template <typename Item>
void Train<Item>::removeItem(const Item& itemA){
    cargoList.erase(std::remove(cargoList.begin(), cargoList.end(), itemA)); //much like add this is so much simpler than the BS i was trying lmao
    //std::cout << "removed item line 23 train.cpp" << std::endl; //debug statement
}
/*
//move an item in the list if defined explicitly.
template <class T>
void Train<T>::moveItem(const T& itemA, int pos1, int pos2){ 
    indexToSwap[2]{pos1, pos2};
    //ok so before with arrays this made sense I promise but now there's actually no reason to do this.
}
*/
template <typename Item>
std::string Train<Item>::moveFunc(const std::string &destination2){
    destination = destination2; //new system W
    return destination;
}

//destroy the train
template <typename Item>
void Train<Item>::destroyEverything(){ //idk your purpose tbh but I could see it being useful.
    //int a = *(20); a* = 10; //troll emoji (it segfaults instead)
    cargoList.clear(); //again it's so much easier than what i was attempting to do with arrays lmao
}

//displays what's on the train
template <typename Item>
int Train<Item>::listItem() const{
    return cargoList.size();
} 

template <typename Item>
bool Train<Item>::isEmpty() const{
    //idk if you're technically an argument or not
    return cargoList.size() == 0;
}

//this should technically be a function to get our weight and display it?
template <typename Item>
double Train<Item>::getWeight() const{
    double total = 0;
    for(const Item &itemA : cargoList){
        total = itemA + total;
    }
    return total;
}

//displays its destination (i'm also assuming people ride for free.)
template <typename Item>
void Train<Item>::displayNextStationAfterSend(){
    for(const Item &itemA : cargoList){
        std::cout << itemA << std::endl;
    }
    //check if there even is anything, i guess a bool would do it but this caused issues
    if(cargoList.size() == 0){
        std::cout << "there is nothing on this train" << std::endl; //originally said "your train is in another castle!"
    }
}

template <typename Item>
std::string Train<Item>::getDestination() const{
   return destination;
}