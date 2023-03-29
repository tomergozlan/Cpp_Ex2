/// Created by tomergozlan on 3/24/23.
/// the headers guards ensure that this header file is only included once in the program.
#ifndef CPP_EX2_MAIN_GAME_H
#define CPP_EX2_MAIN_GAME_H

#include <iostream>
#include "player.hpp" /// provides access to the Player class.

namespace ariel {

    class Game {
    private:
        Player player1; /// A field with private permission that describes the first player in the game .
        Player player2; /// A field with private permission that describes the second player in the game .
    public:
        Game(Player player1,Player player2); /// A constructor of the class.
        void playTurn();/// Simulates a single turn in the game.
        void printLastTurn();/// Print the last turn stats.
        void playAll();/// Playes the game untill the end.
        void printWiner();/// Prints the name of the winning player.
        void printLog();/// Prints all the turns played one line per turn (same format as game.printLastTurn()).
        void printStats();/// For each player prints basic statistics.

    };
}

#endif ///CPP_EX2_MAIN_GAME_H
