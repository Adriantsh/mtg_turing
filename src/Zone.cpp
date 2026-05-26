#include "Zone.h"
#include <iostream>
#include <iomanip>

Zone::Zone() {
}

Zone::~Zone() {
    for (auto p = board.begin(); p != board.end(); p++) {
        delete *p;
    }
}

void Zone::addPermanent(Permanent* permPtr) {
    board.push_back(permPtr);
}

void Zone::removePermanent(int index) {
    if (index < 0 || index >= board.size()) return;

    delete board[index];
    board.erase(board.begin() + index);
}

void Zone::buffCreatureType(std::string subtype, int amt) {
    for (auto perm : board) {
        if (perm->isSubtype(subtype) && perm->isCreature()) {
            perm->incrementToughness(amt);
        }
    }
}

void Zone::buffCreatureNotType(std::string, int amt) {
    // TODO: implement later
}

Permanent* Zone::copyPermanentAt(int index) const{
     return board[index]->clone();
}

void Zone::implySubtype(std::string subtype1, std::string subtype2) {
    for (auto perm : board) {
        if (perm->isSubtype(subtype1)) {
            perm->addSubtype(subtype2);
        }
    }
}

void Zone::display() const {
    int fieldWidth[5] = {5, 15, 15, 15, 20} ;
    std::cout << std::left << std::setw(fieldWidth[0]) << "#:"
              << std::left << std::setw(fieldWidth[1]) << "Type:"
              << std::left << std::setw(fieldWidth[2]) << "Toughness:"
              << std::left << std::setw(fieldWidth[3]) << "Token?"
              << "Subtypes:\n";
    for (int i = 0; i < 70; i++)
        std::cout << "-";
    std::cout << std::endl;
    if (!board.empty()) {
        int i = 0;
        for (auto p : board) {
            i++;
            std::cout << std::left << std::setw(fieldWidth[0]) << i;
            std::cout << std::left << std::setw(fieldWidth[1]) << p->getType();
            if (p->isType("Creature")) {
                std::cout << std::left << std::setw(fieldWidth[2]) << p->getToughness();
            } else {
                std::cout << std::left << std::setw(fieldWidth[2]) << "-";
            }
            if (p->isToken()) {
                std::cout << std::left << std::setw(fieldWidth[3]) << "token";
            } else {
                std::cout << std::left << std::setw(fieldWidth[3]) << "nontoken";
            }
            p->displaySubtypes();
            std::cout << std::endl;
        }
    }
}

bool Zone::isCreature(int index) const {
    return board[index]->isCreature();
}

bool Zone::isDead(int index) const {
    return (board[index]->getToughness() <= 0);
}

bool Zone::isToken(int index) const {
    return board[index]->isToken();
}

int Zone::getNumPerms() const {
    return board.size();
}

const std::vector<Permanent*>& Zone::getBoard() const {
    return board;
}

