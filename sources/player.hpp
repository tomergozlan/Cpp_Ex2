/// Created by Tomer Gozlan on 24/03/2023.

/// the headers guards ensure that this header file is only included once in the program.
#ifndef CPP_EX2_MAIN_PLAYER_H
#define CPP_EX2_MAIN_PLAYER_H
#include <iostream>
#include <string.h> /// provides the std::string class.

using namespace std;

/// By placing these classes within the ariel namespace, the code ensures that they will have
/// unique names and that they will not conflict with other code that uses the same names.

namespace ariel {
    class Player {
    private:
        std::string name; /// A field with private permission that describes the player's name.
    public:
        Player(std::string name); /// A constructor of the class.
        /// A public methods that supports the demo file and relevant to the player class.
        int stacksize(); /// Returns the number of cards the player currently has in their hand.
        int cardesTaken();/// Returns the total number of cards that the player has taken so far.
    };
}

#endif //CPP_EX2_MAIN_PLAYER_H