/// Created by tomergozlan on 3/24/23.

#include "sources/player.h"
#include "sources/game.h"

#include "doctest.h"
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Test case 1: Initialize player with empty name") {
    CHECK_THROWS_AS(Player p(""),std::invalid_argument);
}

TEST_CASE("Test case 2: Initialize game with same player") {
    Player p1("Alice");
    CHECK_THROWS_AS(Game(p1,p1),std::invalid_argument);
}

TEST_CASE("Test case 3: Initialize game with same player names") {
    Player p1("Bob");
    Player p2("Bob");
    CHECK_THROWS_AS(Game(p1,p2),std::invalid_argument);
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
    game.playTurn();
    CHECK_THROWS_AS(game.playTurn(), std::logic_error);
}

TEST_CASE("Test case 8: Test printLastTurn() method cannot be used before playTurn() or playAll() methods") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    CHECK_THROWS_AS(game.printLastTurn(), std::logic_error);
    game.playTurn();
    game.printLastTurn();
    game.playAll();
    game.printLastTurn();
}

TEST_CASE("Test case 9: Test game ends correctly when one player has no cards left") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    bool is_game_over = false;
    while (!is_game_over) {
        try {
            game.playTurn();
        } catch (std::exception& e) {
            is_game_over = true;
        }
        if (p1.stacksize()==0 || p2.stacksize()==0) {
            is_game_over = true;
        }
    }
    CHECK(game.printWiner() == "Bob" || game.printWiner() == "Alice");
}

TEST_CASE("Test case 10: Test printLog() prints only one line") {






