#include "Game.h"

Game::Game() {}
Game::~Game() {}

void Game::newPermanent(std::string type) {
    // TODO: Implement now!!
}

void Game::loadBoardstate(std::string fileName) {
    // TODO: Implement now!!    
}

void Game::displayBattlefield() const {
    // TODO: implement later
}

void Game::displayGraveyard() const {
    // TODO: implement later
}

bool Game::destroyPermanent(int id) {
    return true;
    // TODO: implement later
}

void Game::buffCreaturesType(int amt, std::string) {
    // TODO: implement later
}

void Game::buffCreaturesNotType(int amt, std::string) {
    // TODO: implement later
}
void Game::destroyDeadCreatures() {
    // TODO: implement later
}

void Game::run(Action initialAction, int maxTriggers, std::string outputFile) {
    // TODO: implement later
}

int Game::getNumTriggers() const {
    return 0;
    // TODO: implement later
}