// Holds objects that live on the battlefield, are either token or non-token.
// Creature class is derived from this class
// Permanents have a type and a set of subtypes, and a bool to determine if they are tokens

#ifndef PERMANENT_H
#define PERMANENT_H

#include <string>
#include <set>

class Permanent {
private:
    std::string type;
    std::set<std::string> subtypes;
    bool token;
public:
    Permanent();
    Permanent(std::string type, std::set<std::string> subtypes, bool isToken);
    virtual ~Permanent();
    void displaySubtypes() const;
    std::string getType() const;
    std::set<std::string> getSubtypes() const;
    bool isType(std::string type) const;
    bool isSubtype(std::string subtype) const;
    void addSubtype(std::string subtype);
    bool isToken() const;
    virtual void incrementToughness(int amt);
    virtual int getToughness() const;
    int getNumSubtypes() const;
    virtual Permanent* clone() const;
    bool isCreature() const;
};

#endif
