#include "Creature.h"

Creature::Creature(std::string type, std::set<std::string> subtypes, bool isToken, int toughness)
    : Permanent(type, subtypes, isToken) {
        this->toughness = toughness;
}

Creature::~Creature() {}

int Creature::getToughness() const {
    // TODO: implement this later
    return 0;
}

void Creature::incrementToughness(int amt) {

}
