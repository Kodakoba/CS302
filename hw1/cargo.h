//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//CARGO.H - an ITEM class?! yeah it's a cargo object we carry around :)
//should be straight forward. it is an object that shrimply needs a type and weight
#ifndef CARGO_H
#define CARGO_H

#include <iostream> //for overloads I THINK
#include <string> //this is important for names.

//no we are not using namespaces that's cringe is what im told.

class Cargo{

    //how much does it weigh
    double weight;
    //what IS it?
    std::string type; //originally was name because i assumed object<template>.getName() would work.

public:
    //default object?
    Cargo() = default;
    Cargo(const std::string &newType, const double &newWeight);
    //yay
    //Cargo(const Cargo&);
    //weight getter and setter
    void setWeight(const double &newWeight);
    //get
    double getWeight() const;
    //type getter setter
    void setType(const std::string &newType);
    //apt-get
    std::string getType() const;
    //OOL for adding weight (rhs just means right hand side cause thats how we do math)
    double operator+(const double &rhs) const;
    //OOL for comparing weight
    bool operator==(const Cargo &rhs) const;
    //output thing i referenced from CS202 and modified (we love assignment 14)
    friend std::ostream &operator<<(std::ostream &out, const Cargo &rhs);

    ~Cargo(){}; //deconstructor, i thought it would help with an error but i'm gonna leave it anyways
};


#endif