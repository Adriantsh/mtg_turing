// Inherits from permanent class
// Creatures also have toughness

#ifndef CREATURE_H
#define CREATURE_H

#include "Permanent.h"

class Creature : public Permanent {
private:
    int toughness;
public:
    Creature(std::string type, std::set<std::string> subtypes, bool isToken, int toughness);
    ~Creature();
    int getToughness() const;
    void incrementToughness(int amt);
};

#endif