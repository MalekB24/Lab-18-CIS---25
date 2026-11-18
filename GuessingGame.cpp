#include "guessingGame.h"

#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

GuessingGame::GuessingGame(int minValue, int maxValue)
    : secretNumber(0), guessCount(0), Max(maxValue), Min(minValue) {
    if (minValue > maxValue) {
        throw std::invalid_argument("The minimum value cannot exceed the maximum value.");
    }

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(Min, Max);
    secretNumber = distribution(generator);
}

int GuessingGame::checkGuess(int guess) const {
    if (guess < secretNumber) {
        return -1;
    }
    if (guess > secretNumber) {
        return 1;
    }
    return 0;
}

void GuessingGame::play() {
    std::string line;

    std::cout << "Guess a number between " << Min << " and " << Max
              << ", or enter q to quit.\n";

    while (true) {
        std::cout << "Your guess: ";
        if (!std::getline(std::cin, line)) {
            std::cout << "\nInput ended. The game is over after "
                      << guessCount << " valid guess(es).\n";
            return;
        }

        std::istringstream lineStream(line);
        std::string token;
        std::string extra;
        if (!(lineStream >> token)) {
            std::cout << "Invalid input. Enter a number or q to quit.\n";
            continue;
        }

        if (token == "q" && !(lineStream >> extra)) {
            std::cout << "You quit after " << guessCount
                      << " valid guess(es).\n";
            return;
        }

        std::istringstream numberStream(token);
        int guess;
        char trailingCharacter;
        if (!(numberStream >> guess) || (numberStream >> trailingCharacter) ||
            (lineStream >> extra)) {
            std::cout << "Invalid input. Enter a whole number or q to quit.\n";
            continue;
        }

        if (guess < Min || guess > Max) {
            std::cout << "That guess is outside the range " << Min << " to "
                      << Max << ". Try again.\n";
            continue;
        }

        ++guessCount;
        const int result = checkGuess(guess);
        if (result == 0) {
            std::cout << "Correct! You guessed the number in " << guessCount
                      << " valid guess(es).\n";
            return;
        }
        if (result < 0) {
            std::cout << "Too low.\n";
        } else {
            std::cout << "Too high.\n";
        }
    }
}
