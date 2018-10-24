#pragma once

#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame 
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool IsLowercase(FString Word) const;
	
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO create richer return val
	FBullCowCount SubmitValidGuess(FString);

private: // see constructor for initialization 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	// 'auto' type means the compiler decides the type for us
	bool IsIsogram(FString Word) const;  
};