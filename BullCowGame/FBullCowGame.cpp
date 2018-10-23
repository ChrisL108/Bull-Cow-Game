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

	const FString HIDDEN_WORD = "tester";
	MyHiddenWord = HIDDEN_WORD;


	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	/**if ( FBullCowCount.Bulls == GetHiddenWordLength() )
	{
		return true;
	}**/
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{

	// if guess not isogram - return err
	if (false) {return EGuessStatus::Not_Isogram;}

	// if guess is not lowercase - return err
	else if (false) {return EGuessStatus::Not_Lowercase;}

	// if guess length wrong - return err
	else if (Guess.length() != GetHiddenWordLength() )
		{return EGuessStatus::Wrong_Length;}

	// all good
	else { return EGuessStatus::OK; }
	

}
// submits valid guess and receive counts
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount; 
	int32 WordLength = MyHiddenWord.length(); //assuming same as guess

	// loop through all letters in the hidden word
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++)
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			// for each letter: compare letters against hidden word
			if (HWChar == GChar){
				if (Guess[GChar] == MyHiddenWord[HWChar]) { // if they are in the same place   
					BullCowCount.Bulls++;
 				} else {
					BullCowCount.Cows++; 
				}
				
			} 

		}
	}
	return BullCowCount;
}
