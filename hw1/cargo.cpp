//TRAIN.CPP - by Lloyd Cargo
//HW1 - Transporter
//CARGO.CPP - unlike my last name, it has an implementation that seems to be a little easily agitated.
//ultramode idfk its late
#include "cargo.h"
//inherits all its used libraries

//borrowing from Train since friend says this is allowed
Cargo::Cargo(const std::string &newType, const double &newWeight):type(newType), weight(newWeight){}
//weight getter setter
void Cargo::setWeight(const double &newWeight){
    weight = newWeight;
}

double Cargo::getWeight() const{
    return weight;
}
//type setget
void Cargo::setType(const std::string &newType){
    type = newType;
}

std::string Cargo::getType() const{
    return type;
}
//im praying this //// works
double Cargo::operator+(const double &rhs) const{
    return weight + rhs;
}

bool Cargo::operator==(const Cargo &rhs) const{
    return type == rhs.type && weight == rhs.weight;
}
//"CS202 says you do" - Saul Goodman
std::ostream &operator<<(std::ostream &out, const Cargo &rhs){
    out << rhs.type << " " << rhs.weight << "kg";
    return out;
}