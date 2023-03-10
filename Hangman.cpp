#include "Hangman.h"

/**
 * Executes the game's functions, besides randomization which is performed by getWord()
 */
void Hangman::runGame()
{
    while(!game)
    {
        // Clearing and initializing to 0 for next round in case user wants to play again
        guessedLetters.clear();
        totalGuesses = 0;
        correctGuesses = 0;
        incorrectGuesses = 0;

        // Greeting
        cout << endl;
        cout << "Welcome to Hangman!" << endl;
        getWord();
        cout << "Your word has " << randomWord.length() << " letters." << endl;

        mysteryWord = string(randomWord.length(), '_'); // Hiding the word

        // Asking for the user input until the word is guessed correctly
        while (mysteryWord != randomWord)
        {
            cout << "Enter a letter: ";
            cout << endl;
            cin >> userGuess;
            userGuess = tolower(userGuess); // Fixing case sensitivity

            // Checking if letter has been guessed - we do not know the amount of guesses taken
            if (guessedLetters.find(userGuess) != string::npos)
            {
                cout << "This letter has been guessed already. Try again." << endl;
                continue; // Keep going with the loop
            }

            guessedLetters += userGuess; // Adding user input to the string of guessed chars

            correct = false; // Reset bool value
            for (int i = 0; i < randomWord.length(); i++)
            {
                if (tolower(randomWord[i]) == userGuess)
                {
                    mysteryWord[i] = userGuess; // Replacing the '_' by the correct letter in the correct place
                    correct = true;
                    correctGuesses++;
                }
            }
            totalGuesses++;
            if (!correct)
            {
                incorrectGuesses++;
            }
//            cout << randomWord << endl; // Testing
            cout << mysteryWord << endl;
            cout << endl;
            cout << "Guessed letters: " << guessedLetters << endl; // Displaying the string of guessed letters
            cout << "Total guesses: " << totalGuesses << endl; // Showing the total amount of guesses
            cout << "Correct guesses: " << correctGuesses << endl; // Showing the total amount of correct guesses
            cout << "Incorrect guesses: " << incorrectGuesses << endl; // Showing the total amount of wrong guesses
        }
        cout << "Success! You have guessed the word '" << randomWord << "' after " << totalGuesses
                                                                                        << " attempts." << endl;

        // Asking if user wants to play again
        cout << "Would you like to play again?(Y/N)" << endl;
        cin >> playAgain;
        playAgain = tolower(playAgain);
        if (playAgain == 'y')
        {
            game = false;
        } else if (playAgain == 'n')
        {
            game = true;
        }
    }
    cout << "Thank you for playing! I will see you next time!" << endl;
}

/**
 * @return random word chosen from the list wordList
 */
string Hangman::getWord()
{
    // Randomizing
    srand(time(NULL));
    randomWord = wordList[rand() % 10];
    return randomWord;
}
