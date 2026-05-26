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
#include "Zone.h"
#include <map>
#include <iterator>
#include <set>

class Game {
private:
    Zone battlefield;
    Zone graveyard;
    int numActions;
public:
    Game(); 
    ~Game();

    class FileNotFound {};

    void display() const;
    void loadBoardstate(std::string fileName);
    void destroyDeadCreatures();
    void run(Action initialAction, int maxTriggers, std::string outputFile);
    int getNumActions() const;
    const Zone& getBattle() const;   // For testing only
    const Zone& getGrave() const;   // For testing only

    void implySubtype(std::string subtype1, std::string subtype2);
    void buffSubtype(std::string subtype, int amt);
};

#endif 