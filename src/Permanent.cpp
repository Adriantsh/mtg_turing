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
    return (subtypes.count(subtype) > 0);
}

void Permanent::addSubtype(std::string subtype) {
    subtypes.insert(subtype);
}

bool Permanent::isToken() const {
    return token; 
}

// Overwritten in Creature class
int Permanent::getToughness() const {
    return 0;
}
void Permanent::incrementToughness(int amt) {}

int Permanent::getNumSubtypes() const {
    return subtypes.size();
}

Permanent* Permanent::clone() const {
    return new Permanent(*this);
}

bool Permanent::isCreature() const {
    return (this->isType("Creature"));
}