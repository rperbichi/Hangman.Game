#ifndef HANGMANGAME_HANGMAN_H
#define HANGMANGAME_HANGMAN_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Hangman
{
public:
    // Variables:
    string wordList[10] = {"phone", "computer", "card", "dog", "brick", "brazil",
                           "chile", "byu", "cougars", "home"}; // List of possible words
    string randomWord; // Stores the word randomly selected from the list
    string mysteryWord; // Stores the new string with '_ '
    string guessedLetters; // Stores each letter that ahs been guessed
    char userGuess; // Stores the user guess
    char playAgain; // Stores the user's response to whether or not they want to play again
    int totalGuesses; // Stores total number of guesses
    int correctGuesses; // Stores correct guesses
    int incorrectGuesses; // Stores wrong guesses
    bool correct = false; // Will be used to run the program as long as the letter is not correct
    bool game = false; // Will be used to run the game in case of playAgain = yes

    // Methods:
    void runGame();
    string getWord();
};


#endif //HANGMANGAME_HANGMAN_H
