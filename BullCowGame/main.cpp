#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int32;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

//Intialize Game instance
FBullCowGame CLGame;


int main() { 
	do { 
		PrintIntro(); 
		PlayGame(); 
	} while (AskToPlayAgain());

	return 0;  
}

void PlayGame()
{	
	CLGame.Reset();
	int32 MaxTries = CLGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// TODO change FOR to WHILE loop once we are validating guesses
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = CLGame.SubmitGuess(Guess);
		// Print num of bulls/cows
		std::cout << "Bulls: " << BullCowCount.Bulls << " / " << "Cows: " << BullCowCount.Cows << "\n\n";
	}
	// TODO summarize game
}

void PrintIntro() 
{
	const int32 WORD_LENGTH = CLGame.GetHiddenWordLength();
	std::cout << "The WORD LENGTH is " << WORD_LENGTH << ".. try guessing the isogram!" << std::endl;
	return;
}

// loop continually until user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		int32 CurrentTry = CLGame.GetCurrentTry();
		std::cout << "Try #" << CurrentTry << ": ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		EGuessStatus Status = CLGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case Not_Isogram:
			std::cout << "Please enter an Isogram.\n";
			break;
		case Wrong_Length:
			std::cout << "Please enter a " << CLGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case Not_Lowercase:
			std::cout << "Please enter lowercase letters only.\n";
			break;
		default:
			return Guess;
		}
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain()
{
	FText Answer = "";
	std::cout << "Would you like to play again? (y/n) ";
	getline(std::cin, Answer);
	if ((Answer[0] == 'y') || Answer[0] == 'Y')
	{ return true; }
	else 
	{ return false; }
}
