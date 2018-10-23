#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //constructor

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)  // Receives valid guess (Guess)
{
	// incrememnt turn number
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	// loop through all letters in Guess
	for (int32 i = 0; i < GuessLength; i++)
	{
		// compare letter against hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// for each letter: compare letters against hidden word
			if (Guess[i] == MyHiddenWord[i])
			{
				
				if (i = j) {  // if they are in the same place
					BullCowCount.Bulls++;
				} else {
					BullCowCount.Cows++; 
				}
				
			} 

		}
	}
	
	return BullCowCount;
}
