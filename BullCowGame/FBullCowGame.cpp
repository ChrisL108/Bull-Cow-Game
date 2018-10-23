#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //constructor

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 2;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "Chris";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; // TODO make actual error
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)  // Receives valid guess (Guess)
{
	// incrememnt turn number
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();
	//bool GameWon = IsGameWon() = true;

	// loop through all letters in Guess
	for (int32 Word_Ind = 0; Word_Ind < WordLength; Word_Ind++)
	{
		// compare letter against hidden word
		for (int32 Guess_Ind = 0; Guess_Ind < WordLength; Guess_Ind++)
		{
			// for each letter: compare letters against hidden word
			if (Guess[Guess_Ind] == MyHiddenWord[Word_Ind]){
				if (Word_Ind == Guess_Ind) {  // if they are in the same place
					BullCowCount.Bulls++;
					//if (BullCowCount.Bulls == WordLength) { IsGameWon = true; }
				} else {
					BullCowCount.Cows++; 
				}
				
			} 

		}
	}
	
	return BullCowCount;
}
