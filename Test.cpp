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
    CHECK_THROW(Player p(""),std::invalid_argument);
}

TEST_CASE("Test case 2: Initialize game with same player") {
    Player p1("Alice");
    CHECK_THROW(Game(p1,p1),std::invalid_argument);
}

TEST_CASE("Test case 3: Initialize game with same player names") {
    Player p1("Bob");
    Player p2("Bob");
    CHECK_THROW(Game(p1,p2),std::invalid_argument);
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
    CHECK_THROW(game.playTurn(), std::logic_error);
}

TEST_CASE("Test case 8: Test printLastTurn() method cannot be used before playTurn() or playAll() methods") {
    Player p1("Bob");
    Player p2("Alice");
    Game game(p1, p2);
    CHECK_THROW(game.printLastTurn(), std::logic_error);
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
        CHECK_NOTHROW(game.printLastTurn());// prints the name of the winning player
        CHECK_NOTHROW(game.printStats());// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        CHECK_NOTHROW(game.printLog());// prints all the turns played one line per turn (same format as game.printLastTurn())
        CHECK_NOTHROW(game.printWiner());//prints last turn
    }







