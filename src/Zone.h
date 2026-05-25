// Battlefield and graveyard are Zones held by Game class

#ifndef ZONE_H
#define ZONE_H

#include "Permanent.h"
#include "Creature.h"
#include <vector>

class Zone {
private:
    std::vector<Permanent*> board;
    int idsUsed;
    int numPerms;
public:
    Zone();
    ~Zone();
    void addPermanent(Permanent* perm);
    void removePermanent(int id);
    void buffCreaturesType(int amt, std::string);
    void buffCreaturesNotType(int amt, std::string);
    void copyPermanentAt(int id, Permanent& newPerm);
    void typalImply(std::string type1, std::string type2);
    void display() const;
    bool isDead(int id);
    bool isToken(int id);
    int getNumPerms();
};

#endif