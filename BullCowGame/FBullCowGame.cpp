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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
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

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; //TODO make actual error
}
