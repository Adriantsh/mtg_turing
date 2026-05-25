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
    void buffCreaturesType(int amt, std::string);
    void buffCreaturesNotType(int amt, std::string);
    void copyPermanentAt(int index, Permanent* permPtr);
    void typalImply(std::string type1, std::string type2);
    void display() const;
    bool isDead(int index);
    bool isToken(int index);
    int getNumPerms() const;
    const std::vector<Permanent*>& getBoard() const;   // For testing only
};

#endif