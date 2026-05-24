#include "Game.h"

int main() {

    std::string initialBoardFile = "initialBoardState.txt";
    std::string outputFile = "runlog.txt";

    Game game;
    game.loadBoardstate(initialBoardFile);

    Action initialAction;

    int maxActions = 20;
    game.run(initialAction, maxActions, outputFile);

    return 0;
}