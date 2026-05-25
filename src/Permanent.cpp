#include "Permanent.h"
#include <iostream>

Permanent::Permanent()
    : type("None"), subtypes({}), token(true) {}

Permanent::Permanent(std::string type, std::set<std::string> subtypes, bool isToken) 
    : type(type), subtypes(subtypes), token(isToken) {}
    
Permanent::~Permanent() {}

void Permanent::displaySubtypes() const {
    if (subtypes.empty())
        std::cout << "None";
    else {
        for (auto it = subtypes.begin(); it != subtypes.end(); it++) {
            std::cout << *it;
            if (it != --subtypes.end()) {
                std::cout << ",";
            }
            std::cout << " ";
        }
    }
}

std::string Permanent::getType() const {
    return type;
}

std::set<std::string> Permanent::getSubtypes() const {
    // TODO: implement later
    return {};
}

bool Permanent::isType(std::string testType) const {
    return (type == testType);
}

bool Permanent::isSubtype(std::string subtype) const {
    // TODO: implement later
    return true;
}

void Permanent::addSubtype(std::string subtype) {
    // TODO: implement later
}

bool Permanent::isToken() const {
    return token; 
}

int Permanent::getToughness() const {
    return 0;
}