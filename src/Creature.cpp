#include "Creature.h"

Creature::Creature() {}
Creature::Creature(std::string type, std::set<std::string> subtypes, bool isToken, int tough)
    : Permanent(type, subtypes, isToken) {
        toughness = tough;
}

Creature::~Creature() {}

int Creature::getToughness() const {
    return toughness;
}

void Creature::incrementToughness(int amt) {

}
