#include <iostream>
#include <cassert>
#include "../src/Game.h"

// TODO: Add tests for your const/side-effect-free functions first
// These are the easiest to test (see lecture notes)

bool test_good_boardstate() {

    std::string goodBoard = "../tests/goodBoard.txt";
    Game game;
    game.loadBoardstate(goodBoard);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    const std::vector<Permanent*> grave = game.getGrave().getBoard();

    if (battle[0]->getType() != "Creature") return false;
    if (battle[0]->getToughness() != 2) return false;
    if (!(battle[0]->isToken())) return false;
    if (!(battle[0]->isSubtype("Bear"))) return false;
    if (!(battle[0]->isSubtype("Cat"))) return false;
    if (battle[0]->getNumSubtypes() != 2) return false;

    if (grave[0]->getType() != "Artifact") return false;
    if (grave[0]->getToughness() != 0) return false;
    if (grave[0]->isToken()) return false;
    if (grave[0]->getNumSubtypes() != 0) return false;

    return true;
}


bool test_empty_boardstate() {

    std::string emptyBoard = "../tests/empty.txt";
    Game game;
    game.loadBoardstate(emptyBoard);

    if (game.getBattle().getNumPerms() != 0) return false;
    if (game.getGrave().getNumPerms() != 0) return false;

    return true;
}

bool test_bad_file() {

    std::string badFile = "tests/thisFileDoesNotExist.txt";
    Game game;
    try {
        game.loadBoardstate(badFile);
    } catch (Game::FileNotFound) {
        return true;
    }
    return false;

    std::cout << "Flag";
}

bool test_buff_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.buffSubtype("Cat", 1);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    if (battle[0]->getToughness() != 1) return false;
    if (battle[1]->getToughness() != 3) return false;
    if (battle[2]->getToughness() != 4) return false;

    return true;
}

bool test_add_subtype_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.implySubtype("Cat", "Lion");
    game.implySubtype("Lion", "Tiger");

    const std::vector<Permanent*> battle = game.getBattle().getBoard();

    if (!(battle[1]->isSubtype("Lion"))) return false;
    if (!(battle[1]->isSubtype("Tiger"))) return false;
    if (!(battle[2]->isSubtype("Lion"))) return false;
    if (!(battle[2]->isSubtype("Tiger"))) return false;
    if (battle[0]->isSubtype("Lion")) return false;
    if (battle[0]->isSubtype("Tiger")) return false;

    return true;
}

bool test_remove_dead_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.buffSubtype("Bear", -1);
    game.destroyDeadCreatures();
    game.display();

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    const std::vector<Permanent*> grave = game.getGrave().getBoard();
    
    if (game.getBattle().getNumPerms() != 2) return false;
    if (game.getGrave().getNumPerms() != 1) return false;
    if (!(grave[0]->isSubtype("Bear"))) return false;
    if (grave[0]->getToughness() != 0) return false;

    return true;
}

int main() {
    std::cout << "Running tests..." << std::endl;

    if (!test_good_boardstate()) return 1;
    if (!test_empty_boardstate()) return 1;
    if (!test_bad_file()) return 1;
    if (!test_buff_creatures()) return 1;
    if (!test_remove_dead_creatures()) return 1;

    std::cout << "\nAll tests completed." << std::endl;
    return 0;
}
