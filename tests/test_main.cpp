#include <iostream>
#include <cassert>
#include "../src/Game.h"

// TODO: Add tests for your const/side-effect-free functions first
// These are the easiest to test (see lecture notes)

void test_good_boardstate() {

    std::string goodBoard = "../tests/goodBoard.txt";
    Game game;
    game.loadBoardstate(goodBoard);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    const std::vector<Permanent*> grave = game.getGrave().getBoard();

    assert(battle[0]->getType() == "Creature");
    assert(battle[0]->getToughness() == 2);
    assert(battle[0]->isToken());
    assert(battle[0]->isSubtype("Bear"));
    assert(battle[0]->isSubtype("Cat"));
    assert(battle[0]->getNumSubtypes() == 2);

    assert(grave[0]->getType() == "Artifact");
    assert(grave[0]->getToughness() == 0);
    assert(grave[0]->isToken() == false);
    assert(grave[0]->getNumSubtypes() == 0);
}


void test_empty_boardstate() {

    std::string emptyBoard = "../tests/empty.txt";
    Game game;
    game.loadBoardstate(emptyBoard);

    assert(game.getBattle().getNumPerms() == 0);
    assert(game.getGrave().getNumPerms() == 0);
}

void test_bad_file() {

    std::string badFile = "tests/thisFileDoesNotExist.txt";
    Game game;
    try {
        game.loadBoardstate(badFile);
    } catch (Game::FileNotFound) {
        return;
    }
    assert(false);
}

void test_buff_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.buffSubtype("Cat", 1);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    assert(battle[0]->getToughness() == 1);
    assert(battle[1]->getToughness() == 3);
    assert(battle[2]->getToughness() == 4);
}

void test_add_subtype_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.implySubtype("Cat", "Lion");
    game.implySubtype("Lion", "Tiger");

    const std::vector<Permanent*> battle = game.getBattle().getBoard();

    assert(battle[1]->isSubtype("Lion"));
    assert(battle[1]->isSubtype("Tiger"));
    assert(battle[2]->isSubtype("Lion"));
    assert(battle[2]->isSubtype("Tiger"));
    assert(!battle[0]->isSubtype("Lion"));
    assert(!battle[0]->isSubtype("Tiger"));
}

void test_remove_dead_creatures() {

    std::string board = "../tests/creatureBoard.txt";
    Game game;
    game.loadBoardstate(board);
    game.buffSubtype("Bear", -1);
    game.destroyDeadCreatures();

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    const std::vector<Permanent*> grave = game.getGrave().getBoard();
    
    assert(game.getBattle().getNumPerms() == 2);
    assert(game.getGrave().getNumPerms() == 1);
    assert(grave[0]->isSubtype("Bear"));
    assert(grave[0]->getToughness() == 0);
}

void test_no_buffs_or_implies() {
    std::string board = "../tests/goodBoard.txt";
    Game game;
    game.loadBoardstate(board);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    
    int before = battle[0]->getToughness();
    game.applyBuffs();
    int after = battle[0]->getToughness();

    assert(before == after);
}

void test_buffs_and_implies() {
    std::string board = "../tests/test_buffs_and_implies.txt";
    Game game;
    game.loadBoardstate(board);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    
    assert(battle[0]->getToughness() == 1);
    game.implySubtypes();
    game.applyBuffs();
    assert(battle[0]->getToughness() == 2);
}

void test_swap_order_implies() {
     std::string board = "../tests/test_swap_order_implies.txt";
    Game game;
    game.loadBoardstate(board);

    const std::vector<Permanent*> battle = game.getBattle().getBoard();
    
    assert(battle[0]->isSubtype("Fish") == false);
    game.implySubtypes();
    assert(battle[0]->isSubtype("Fish") == true);
}

int main() {
    std::cout << "Running tests..." << std::endl;

    test_good_boardstate();
    test_empty_boardstate();
    test_bad_file();
    test_buff_creatures();
    test_add_subtype_creatures();
    test_remove_dead_creatures();
    test_no_buffs_or_implies();
    test_buffs_and_implies();
    test_swap_order_implies();

    std::cout << "\nAll tests completed." << std::endl;
    return 0;
}
