// Holds of event objects of the form:
// A [Creature] with types [Bear, Frog] was [Created]
// An [Enchantment] with types [None] was [Destroyed]
// A [Creature] with types [Bear] was [Buffed]

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <set>

class Event {
private:
    std::string event_action;
    std::string type;
    std::set<std::string> sub_types;
public:
    Event();
    Event(std::string action, std::string type, std::set<std::string> sub_types);
    ~Event();
    void display() const;
    std::string getEventAction() const;
    std::string getEventType() const;
    std::string getEventSubTypes() const;
    bool isEventType(std::string) const;
    bool isEventSubType(std::string) const;
};

#endif 