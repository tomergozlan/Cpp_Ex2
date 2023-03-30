/// Created by tomergozlan on 3/24/23.

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include "doctest.h"
#include <iostream>
#include <string>


using namespace ariel;
using namespace std;

TEST_CASE("Test case 1: Initialize player with empty name") {
    CHECK_THROWS(Player (""));
}

TEST_CASE("Test case 2: Initialize game with same player") {
    Player p1("Alice");
    CHECK_THROWS(Game(p1,p1));
}

TEST_CASE("Test case 3: Initialize game with same player names") {
    Player p1("Bob");
    Player p2("Bob");
    CHECK_THROWS(Game(p1,p2));
}

TEST_CASE("Test case 4: Initialize game with different player names") {
    Player p1("Bob");
    Player p2("Alice");
    CHECK_NOTHROW(Game(p1, p2));
}

TEST_CASE("Test case 5: stack size of new players & after all the games") {
    Player p1("Bob");
    Player p2("Alice");
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() + p2.stacksize() == 0);
}

TEST_CASE("Test case 6: Test player cardesTaken of new player & after all the games") {
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}

TEST_CASE("Test case 7: Test player cannot playTurn() after playAll() ") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test case 8: Test printLastTurn() method cannot be used before playTurn() or playAll() methods") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
    game.playTurn();
    game.printLastTurn();
    game.playAll();
    game.printLastTurn();
}

TEST_CASE("Test case 9: Test game ends correctly") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test case 10: Test every Turn the players have 52 cards") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++) {
        game.playTurn();
        CHECK(p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52);
    }
}

TEST_CASE("Test case 11:Checking that all the print functions work"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test case 12:Checking after one turn"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize()<26);
    CHECK(p2.stacksize()<26);
    CHECK(p1.stacksize()==p2.stacksize());
    CHECK(p1.stacksize()+p2.stacksize()+p1.cardesTaken()+p2.cardesTaken()==52);
}