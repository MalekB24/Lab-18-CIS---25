#include "guessingGame.h"

#include <exception>
#include <iostream>

int main() {
    try {
        GuessingGame game(1, 100);
        game.play();
    } catch (const std::exception& error) {
        std::cerr << "Unable to start the game: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
