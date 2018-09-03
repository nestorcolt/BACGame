#include "FBullCowGameOBJ.h"

using int32 = int;


//Constructor
FBullCowGameOBJ::FBullCowGameOBJ() {
	reset();
}

//Integer methods 
int32 FBullCowGameOBJ::getMaxTries() const {return myMaxTries;}
int32 FBullCowGameOBJ::getCurrentTry() const{return myCurrentTry;}
int32 FBullCowGameOBJ::getHiddenWordLenght() const {return myHiddenWord.length();}

bool FBullCowGameOBJ::isGameWom() const {
	return false;
}


//More stuff like booleans and void
void FBullCowGameOBJ::reset() {

	constexpr int32 MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	const FString HIDDEN_WORD = "plant";
	myHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGameOBJ::CheckGuessValidity(FString) const {
	return false;
}

// receives a VALID guess, increments turn and returns cows
FBullcowCount FBullCowGameOBJ::SubmitGuess(FString Guess) {
	// increment the turn number
	myCurrentTry++;
	// setup a return variable
	FBullcowCount BullCowCount;

	// loop through all letters in the guess
	int32 hiddenWordLenght = myHiddenWord.length();

	for (int32 HWChar = 0; HWChar < hiddenWordLenght; HWChar++){
		for (int32 GChar = 0; GChar < hiddenWordLenght; GChar++){
			if (Guess[GChar] == myHiddenWord[HWChar]) {
				// compare letters against the hidden word
				if (HWChar == GChar) {
					BullCowCount.Bulls++; // increment bulls (MATCH)
				}

				else {
					BullCowCount.Cows++; // increment cows (doesn't match)
				}
			}
		}

	}

	return BullCowCount;
}


FString FBullCowGameOBJ::getWord() {
	return FString();
 }


bool FBullCowGameOBJ::isIsogram(FString) {
	return false;
}


