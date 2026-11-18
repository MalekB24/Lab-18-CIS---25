#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H
// Manages a guessing game where the player tries to find a secret number.
class GuessingGame {
    private:
    int secretNumber;
    int guessCount;
    int Max;
    int Min;
    // Compares the guess with the secret number.
    // Returns -1 if too low, 0 if correct, and 1 if too high.
    int checkGuess(int guess) const;
    public: 
    // Sets the minimum and maximum, chooses a secret number,
    // and initializes the guess count to zero.
    GuessingGame(int minValue, int maxValue);
    // Runs the game: reads guesses, handles invalid input,
    // counts valid guesses, and displays feedback until the player wins or quits.
    void play();
};

#endif