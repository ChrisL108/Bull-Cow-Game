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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
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
			char GuessChar = Guess[Guess_Ind];
			char HiddenChar = MyHiddenWord[Word_Ind];
			// for each letter: compare letters against hidden word
			if (Word_Ind == Guess_Ind){
				if ((GuessChar == HiddenChar) ) {  // if they are in the same place
					BullCowCount.Bulls++;
 				} else {
					BullCowCount.Cows++; 
				}
				
			} 

		}
	}
	
	return BullCowCount;
}
