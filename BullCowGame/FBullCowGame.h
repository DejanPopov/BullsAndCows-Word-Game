#pragma once
#include <string>



class FBullCowGame {
public:
	FBullCowGame(); //Constructor


	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string);
	void Reset(); //TODO make a more rich return value

private:
	// See constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
}; 