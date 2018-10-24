#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameResults();

//Intialize Game instance in global scope
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

	// loop asking for guesses or while the game
	// is NOT won && there are still tries remaining
	while (!CLGame.IsGameWon() && CLGame.GetCurrentTry() <= MaxTries) 
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = CLGame.SubmitValidGuess(Guess);
		// Print num of bulls/cows
		std::cout << "   Bulls: [" << BullCowCount.Bulls << "], " << "Cows: [" << BullCowCount.Cows << "] -- " ;
		std::cout << "(" << CLGame.RemainingTries() + 1 << " attempts left)\n\n";
	}
	PrintGameResults(); // Let the player know if they won or lost
	return;
}



// loop continually until user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid; // set ENUMerator for while loop condition
	do {
		int32 CurrentTry = CLGame.GetCurrentTry();
		std::cout << std::endl << "-Attempt #" << CurrentTry << ":  ";
		
		std::getline(std::cin, Guess);

		Status = CLGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case Not_Isogram:
			std::cout << "Entry is NOT an Isogram (no repeating letters) \n\n";
			break;
		case Wrong_Length:
			std::cout << "Please enter a " << CLGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case Not_Lowercase:
			std::cout << "Please enter lowercase letters only.\n\n";
			break;
		default:
			// assume Guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintIntro()
{
	const int32 WORD_LENGTH = CLGame.GetHiddenWordLength();
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\_ " << std::endl;
	std::cout << " *  |-q_p--- |              |---\\/-| \* " << std::endl;
	std::cout << "    ^  U     ^              ^       ^ " << std::endl;
	std::cout << std::endl << "~~ The WORD LENGTH is " << WORD_LENGTH << 
				  "...  you get " << CLGame.GetMaxTries() << " attempts ~~\n\n";
	std::cout << "||Game Rules" << std::endl;
	std::cout << " |BULL = letter is correct and in the CORRECT spot.\n";
	std::cout << " |COW  = the letter is correct but is in the WRONG spot\n";
	return;
}
bool AskToPlayAgain()
{
	FText Answer = "";
	std::cout << "\n\nWould you like to play again, with the same hidden word? (y/n) ";
	getline(std::cin, Answer);
	if ((Answer[0] == 'y') || Answer[0] == 'Y')
	{ return true; }
	else 
	{ return false; }
}
void PrintGameResults()
{
	if (CLGame.IsGameWon()) {
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
		std::cout << "You have WON!!! Good Job!";
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~\n\n";
	}
	else {
		std::cout << "\nSUCKS TO SUCK\n...loser\n\n";
	}
	return;
}