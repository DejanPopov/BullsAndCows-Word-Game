#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();} //Constructor

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

// recieves valid guess, incrementsturn, and return count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuimng same length as guess

	// loop through all letters in the hidden word
	
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { //if they are in th esame place
					BullCowCount.Bulls++; // increments bulls
				}
				else {
					BullCowCount.Cows++; // increment cows 
				}
			}
		}
	}

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if th eguess isnt an isogram 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isnt all lowercase return the error
	{
		return EGuessStatus::Not_Lower_case;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
}
