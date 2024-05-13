//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//PERSON.H - like a "cargo" but more complicated (and they don't like you asking their weight.)
//implements a person that has a height and a name.
#ifndef PERSON_H
#define PERSON_H

#include <string> //required for names
#include <iostream> //could it get any worse

class Person{

    double height; //was a float but double is easier (also i replaced weight with height trolley)
    std::string name;

public:
    //default constructor for safety?
    Person() = default;
    Person(const std::string &newName, const double &newHeight);
    //don't need the person(Person&) is something im told but will ask about in office hours.
    //height getter setter
    double getHeight();
    //this function takes an input in CM
    void setHeight(const double &newHeight); 
    //Name Getter setter (part 2)
    std::string getName();
    //you should be a string.
    void setName(const std::string &newName);
    //wallet getter,/setter, though it shouldn't actually ever be used!
    //copied from cargo.h
    //greater case
    bool operator>(const Person &rhs) const;
    //lesser case
    bool operator<(const Person &rhs) const;
    //assignment
    bool operator==(const Person &rhs) const;
    //copied from cargo.h, has to do with printing! (CS202)
    friend std::ostream &operator<<(std::ostream &out, const Person &rhs);
    ~Person(){};
};

#endif