//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//PERSON.CPP - the person type. we had 4 revisions, with only 2 published. it works now, even if it really is just a polished turd. IMPLEMENTED!
//im pretty sure this is how this work (i'm going off memory for 99% of this)
#include "person.h"

//copying everything from cargo.cpp lol
Person::Person(const std::string &newName, const double &newHeight):name(newName), height(newHeight){}
//heightgetset
void Person::setHeight(const double &newHeight){
    height = newHeight;
}

double Person::getHeight(){
    return height;
}
//namesetget
void Person::setName(const std::string &newName){
    name = newName;
}

std::string Person::getName(){
    return name;
}
//OOL compares
bool Person::operator>(const Person &rhs) const{
    return height > rhs.height;
}

bool Person::operator<(const Person &rhs) const{
    return height < rhs.height;
}
//assignment
bool Person::operator==(const Person &rhs) const{
    return name == rhs.name && height == rhs.height;
}
//CS202 magic
std::ostream &operator<<(std::ostream &out, const Person &rhs){
    out << rhs.name << " " << rhs.height << "cm";
    return out;
}