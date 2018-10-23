#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = CLGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	// TODO change FOR to WHILE loop once we are validating guesses
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess();
		// TODO Check guess validity
			//  -- CLGame.CheckGuessValidity(Guess)
			// Submit valid response to game instance
			// Print num of bulls/cows

		std::cout << "Your guess was: " << Guess << std::endl << std::endl;
	}
	// TODO summarize game
}

void PrintIntro() 
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, an OKAY word game... I guess" << std::endl;
	return;
}

std::string GetGuess() 
{
	int CurrentTry = CLGame.GetCurrentTry();
	std::cout << "Try #" << CurrentTry << ": "; 
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::string Answer = "";
	std::cout << "Would you like to play again? (y/n) ";
	getline(std::cin, Answer);
	if ((Answer[0] == 'y') || Answer[0] == 'Y')
	{ return true; }
	else 
	{ return false; }
}
