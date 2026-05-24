#include "Game.h"

int main() {

    std::string initBoardFile = "initialBoardState.txt";

    Game game;
    game.loadBoardstate(initBoardFile);

    Action initialAction;

    int maxTriggers = 20;
    game.run(initialAction, maxTriggers);

    return 0;
}