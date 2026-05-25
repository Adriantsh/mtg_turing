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

void Zone::removePermanent(int id) {
    // TODO: implement later
}

void Zone::buffCreaturesType(int amt, std::string) {
    // TODO: implement later
}

void Zone::buffCreaturesNotType(int amt, std::string) {
    // TODO: implement later
}
void Zone::copyPermanentAt(int id, Permanent* permPtr) {
    // TODO: implement later
}

void Zone::typalImply(std::string type1, std::string type2) {
    // TODO: implement later    
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

bool Zone::isDead(int id) {
    return true;
    // TODO: implement later  
}

bool Zone::isToken(int index) {
    return board[index]->isToken();
}

int Zone::getNumPerms() const {
    return board.size();
}

const std::vector<Permanent*>& Zone::getBoard() const {
    return board;
}