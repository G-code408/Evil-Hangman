
#include <string>
#include <iostream>
#include "FamilySet.h"
using namespace std;

bool debug;	// Global variable to indicate debugging

bool PromptYesNoMessage(string msg) {
	while (true) {
		cout << msg << "(y/n) ";
		string response;
		cin >> response;
		if (response == "y")
			return true;
		if (response == "n")
			return false;
		cout << "Please enter y or n..." << endl;
	}
}

int PromptGuesses()
{
	while (true) {
		int len;
		cout << "Please enter how many guesses: ";
		cin >> len;
		if (len > 0)
			return len;
	}
}

int PromptWordLength()
{
	int len;

	// Your code here...
	while (true)
    {
        cout << "Please enter word length: ";
        cin >> len;
        if(len > 0 && len < 29)
            return len;
    }
}

string PromptGuess(string& guessedLetters)
{
	string guess = "";
	while(true)
    {
        cout << "Enter Guess: ";
        cin >> guess;

        bool letterGuessed = false;
        for(int i=0; i<guessedLetters.size(); i++)
        {
            if(guess[0] == guessedLetters[i])
            {
                letterGuessed = true;
            }
        }
        if(guess.size() == 1 && !letterGuessed)
        {
            guessedLetters += guess;
            return guess;
        }

    }

}

string ChooseFamily(string guess, string guessProgress, FamilySet& set)
{
	// filter families by guess and guessProgress/guessPattern

	string maxFamily;

	/*
	 * Use the iterator to loop through each family and
	 * figure out the biggest family size.
	 * Return this family
	 */

	return maxFamily;
}

bool isWin(string guessedProgress)
{
	return guessedProgress.find("*") == string::npos;
}

void PlayEvilHangman(string file)
{
	// Prompt user for word length and number of guesses
	int len = PromptWordLength();
	int guessesLeft = PromptGuesses();

	// Load dictionary based on word length
	cout << "Loading dictionary..." << endl;
	FamilySet families(file, len);

	string guessedLetters = "";
	string correctlyGuessed = "";	// correctly guessed positions
	string guessProgress = "";
	for (int i = 0; i < len; i++)
		guessProgress += "*";

    //string hardCodeWord = "batter";
    string randWord = families.getRandomWord();
    cout << "WORD: " << randWord << endl;

	// Actual game loop...
	while (true) {

		// Your code here...
		cout << endl;
		cout << guessProgress << endl;
		//cout << "Word: " << randWord << endl;
		cout << "Guesses Left: " << guessesLeft << endl;
		cout << "Guessed Letters: " << guessedLetters << endl;
		if(debug)
        {
            cout << "Candidate Words: " << families.numWords() << endl;
            cout << "WORD: " << randWord << endl;
        }
         string guess = PromptGuess(guessedLetters);

         guessesLeft--;
         //if(debug)

         families.filterFamilies(guess,guessProgress);
         for(int i=0; i<len; i++)
         {

             if(guess[0] == randWord[i])
             {
                 guessProgress[i] = guess[0];
             }
         }

         families.setFamily(guessProgress);


		if (isWin(guessProgress)) {
			cout << "Wow! You won!" << endl;
			cout << "The word was " << randWord << endl;
			break;
		}

		if (guessesLeft <= 0) {
			cout << "Wow... you are a really bad guesser..." << endl;
			cout << "The mystery word was " << randWord << endl;
			break;
		}
         randWord = families.getRandomWord();
         cout << "WORD: " << randWord << endl;
	}
}

int main()
{
	string file;
	//cout << "Enter file: ";
	//cin >> file;				// Can comment out this line and include the following while developing
	file = "dictionary.txt";  // Convenient to hard code while developing

	while (true) {
		debug = PromptYesNoMessage("Turn debugging on?");
		PlayEvilHangman(file);
		if (!PromptYesNoMessage("Would you like to play again ?"))
			break;
	}
}
