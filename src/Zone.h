// Battlefield and graveyard are Zones held by Game class

#ifndef ZONE_H
#define ZONE_H

#include "Permanent.h"
#include "Creature.h"
#include <vector>

class Zone {
private:
    std::vector<Permanent*> board;
public:
    Zone();
    ~Zone();
    void addPermanent(Permanent* perm);
    void removePermanent(int index);
    void buffCreatureType(std::string, int amt);
    void buffCreatureNotType(std::string, int amt);
    Permanent* copyPermanentAt(int index) const;
    void implySubtype(std::string subtype1, std::string subtype2);
    void display() const;
    bool isDead(int index) const;
    bool isToken(int index) const;
    bool isCreature(int index) const;
    int getNumPerms() const;
    const std::vector<Permanent*>& getBoard() const;   // For testing only
};

#endif