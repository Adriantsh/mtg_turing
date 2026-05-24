// Actions change the boardstate, but also add new Events.

// Action derived classes:
// Grow: all creatures of subtypes Y get buffed by an amount.                              -> Growth event
// Destroy: destroy all permanents of type X                                               -> Destruction event
// Create: create permanent of type X and subtypes {y1, y2, ...}                           -> Creation event
// Reanimate: return all permanents of type X from the graveyard to the battlefield        -> Creation event
#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <set>
#include "Event.h"

class Action {
private:
    std::set<std::string> type;
    std::set<std::string> subtypes;
    // std::set<Event> eventsCaused;
public:
    Action();
    ~Action();
    void updateFunction();
};

#endif
