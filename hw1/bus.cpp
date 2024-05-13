//BUS.CPP - by Lloyd Cargo
//HW1 - Transporter
//the implementation of the bus class and it's functions as defined by the header. truly the hardest exercise i've ever had. 
//incase you needed this
#include "bus.h"
//#include <iostream> //otherwise debug won't work

//case 1
template<typename Item>
Bus<Item>::Bus(const std::string &newDestination):destination(newDestination){}
//case 2
template<typename Item>
Bus<Item>::Bus(const std::string &newDestination, const int &farePrice2):destination(newDestination), fareprice(farePrice2){}
//case 3
template<typename Item>
Bus<Item>::Bus(std::vector<Item> &newPeopleList):peopleList(newPeopleList){}
//case 4
template<typename Item>
Bus<Item>::Bus(std::vector<Item> &newPeopleList, const std::string &newDestination):peopleList(newPeopleList), destination(newDestination){}
//case 2 + 3 (definitely wasn't on purpose)
template<typename Item>
Bus<Item>::Bus(std::vector<Item> &newPeopleList, const std::string &newDestination, const double &farePrice2):peopleList(newPeopleList), destination(newDestination), fareprice(farePrice2){}
//add stuff to dabus
template<typename Item>
void Bus<Item>::addItem(const Item &itemA){
    peopleList.push_back(itemA);
    std::sort(peopleList.begin(), peopleList.end());
}
//the remove stuff function (copied from train like most the following)
template <typename Item>
void Bus<Item>::removeItem(const Item &itemA){
    peopleList.erase(std::remove(peopleList.begin(), peopleList.end(), itemA), peopleList.end());
    std::cout << "removed item line 29 bus.cpp" << std::endl; //debug statement
}
//does the moving
template <typename Item>
std::string Bus<Item>::moveFunc(const std::string &destination2){
    destination = destination2; //new system W
    return destination;
}
//i still quite like the name of this function, though with train it's funnier to me.
template <typename Item>
void Bus<Item>::destroyEverything(){
    peopleList.clear(); //ezpz
}
//lists stuff on board
template <typename Item>
int Bus<Item>::listItem() const{
    return peopleList.size();
} 
//!empty
template <typename Item>
bool Bus<Item>::isEmpty() const{
    //idk if you're technically an argument or not
    return peopleList.size() == 0;
}

template <typename Item>
void Bus<Item>::setFare(const int &farePrice2){
    fareprice = farePrice2;
}

template <typename Item>
int Bus<Item>::getFare(){
    return fareprice;
}

template <typename Item>
int Bus<Item>::getTotal(){
    return fareprice*peopleList.size();
}

template <typename Item>
void Bus<Item>::displayNextStationAfterSend(){
    for(const Item &itemA : peopleList){
        std::cout << itemA << std::endl;
    }
    //check if there even is anything, i guess a bool would do it but this caused issues
    if(peopleList.size() == 0){
        std::cout << "there is nothing on this bus bruh" << std::endl; //originally said "your train is in another castle!"
    }
}

template <typename Item>
std::string Bus<Item>::getDestination() const{
   return destination;
}