// Triggered ability: has an event as an input and does something depending on output
// Examples:
// Whenever a [Bear] is [destroyed], [create a 2/2 Zombie]
// Whenever a [Enchantment] is [created], [all Bears get -1/-1] 
#ifndef TRIGGER_H
#define TRIGGER_H

#include "Event.h"
#include "Action.h"
#include <string>
#include <set>

class Trigger {
private:
    Event inputEvent;
    Action outputAction;
public:
    Trigger();
    ~Trigger();
    bool isTriggered(Event) const;
    void runAction();
};
#endif