#include "Game.h"
#include <fstream>
#include <iostream>

Game::Game() {
    int numActions = 0;
}

Game::~Game() {}

void Game::loadBoardstate(std::string fileName) {

    std::ifstream inFile;
    inFile.open(fileName);

    std::string currentString;
    std::string permType;
    std::set<std::string> permSubtypes;
    int toughness = 0;
    std::string zone;
    bool isToken;

    bool moreStrings = true;
    
    moreStrings = static_cast<bool>(inFile >> currentString);
    while (moreStrings) {
        permType = currentString;

        if (permType == "Creature") {
            inFile >> currentString;
            toughness = std::stoi(currentString);
        }

        inFile >> currentString;

        if (currentString == "t") {
            isToken = true;
        } else if (currentString == "n") {
            isToken = false;
        }

        inFile >> currentString;
        permSubtypes.clear();
        while (currentString != ";") {
            permSubtypes.insert(currentString);
            inFile >> currentString;
        }

        inFile >> currentString;
        zone = currentString;

        Permanent* permPtr = nullptr;

        if (permType == "Creature") {
            permPtr = new Creature(permType, permSubtypes, isToken, toughness);
        } else {
            permPtr = new Permanent(permType, permSubtypes, isToken);
        }

        if (zone == "b") {
            battlefield.addPermanent(permPtr);
        } else if (zone == "g") {
            graveyard.addPermanent(permPtr);
        }

        moreStrings = static_cast<bool>(inFile >> currentString);
    }
}

void Game::display() const {
    std::cout << "\nBattlefield:\n";
    battlefield.display();
    std::cout << "\nGraveyard:\n";
    graveyard.display();
    std::cout << std::endl;
    std::cin.get();
}

void Game::destroyDeadCreatures() {
    // TODO: implement later
}

void Game::run(Action initialAction, int maxTriggers, std::string outputFile) {
    // TODO: implement later
}

int Game::getNumActions() const {
    return 0;
    // TODO: implement later
}