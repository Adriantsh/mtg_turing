#include "Game.h"
#include <iostream>

int main() {

    std::string initialBoardFile = "src/initialBoardState.txt";

    // std::string outputFile = "runlog.txt";
    
    Game game;
    game.loadBoardstate(initialBoardFile);
    game.display();

    // Action initialAction;

    // int maxActions = 20;
    // game.run(initialAction, maxActions, outputFile);

    return 0;
}