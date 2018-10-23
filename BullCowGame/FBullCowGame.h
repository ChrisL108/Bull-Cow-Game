#pragma once

#include <string>


class FBullCowGame {
public:
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO create richer return val
	bool CheckGuessValidity(std::string); // TODO create richer return val

private: // see constructor for initialization 
	int MyCurrentTry;
	int MyMaxTries;
};