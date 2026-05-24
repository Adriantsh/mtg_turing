// Manager class, runs main game loop, holds the map objects for the battlefield and graveyard
// Also has file loading function
#ifndef GAME_H
#define GAME_H

#include "Permanent.h"
#include "Creature.h"
#include "Trigger.h"
#include "Stack.h"
#include "Event.h"
#include "Action.h"
#include <map>
#include <iterator>
#include <set>

class Game {
private:
    std::map<int, Permanent> battlefield;
    std::map<int, Permanent> graveyard;
    int ids_used;
    int numTriggers;
public:
    Game(); 
    ~Game();
    void displayBattlefield() const;
    void displayGraveyard() const;
    void newPermanent(std::string type);
    void newCreature(int toughness);
    void newCreature(int toughness, std::string subtype);
    void newCreature(int toughness, std::set<std::string> subtypes);
    bool destroyPermanent(int id);
    void buffCreaturesType(int amt, std::string);
    void buffCreaturesNotType(int amt, std::string);
    void destroyDeadCreatures();
    void loadBoardstate(std::string fileName);
    void run(Action initialAction, int maxTriggers);
    int getNumTriggers() const;
};

#endif 