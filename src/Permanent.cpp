#include "Permanent.h"

Permanent::Permanent(std::string type, std::set<std::string> subtypes, bool isToken) 
    : type(type), subtypes(subtypes), token(isToken) {}
    
Permanent::~Permanent() {}

void Permanent::displayTypes() const {
    // TODO: implement later
}

std::string Permanent::getType() const {
    // TODO: implement later
    return "";
}

std::set<std::string> Permanent::getSubtypes() const {
    // TODO: implement later
    return {};
}

bool Permanent::isType(std::string type) const {
    // TODO: implement later
    return true;
}

bool Permanent::isSubtype(std::string subtype) const {
    // TODO: implement later
    return true;
}

void Permanent::addSubtype(std::string subtype) {
    // TODO: implement later
}

bool Permanent::isToken() const {
    // TODO: implement later
    return true; 
}