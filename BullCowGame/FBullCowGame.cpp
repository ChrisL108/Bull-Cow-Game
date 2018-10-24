#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //constructor

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; } // word with 1-2 characters are isograms by nature
	
	TMap<char, bool> LetterSeen; // setup our map

	for (auto Letter : Word)  // for all letters(chars) in Word
	{
		Letter = tolower(Letter); // make letter lowercase
		if (LetterSeen[Letter]) { return false; } 
		else { LetterSeen[Letter] = true; } 
	}
	
	return true;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 6;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if guess not isogram - return err
	if (!IsIsogram(Guess)) 
		{return EGuessStatus::Not_Isogram;}

	// if guess is not lowercase - return err
	else if (!IsLowercase(Guess)) 
		{return EGuessStatus::Not_Lowercase;}

	// if guess length wrong - return err
	else if (Guess.length() != GetHiddenWordLength() )
		{return EGuessStatus::Wrong_Length;}

	// all good
	else { return EGuessStatus::OK; }
}

// receives and submites valid guess and receive counts
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
			if (Guess[GChar] == MyHiddenWord[HWChar]){
				
				if (HWChar == GChar) { // if they are in the same place   
					BullCowCount.Bulls++;
 				} else {
					BullCowCount.Cows++; 
				}
			} 
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}


