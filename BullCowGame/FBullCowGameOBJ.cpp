#include "FBullCowGameOBJ.h"
#include <stdio.h>
#include <iostream>
#include < conio.h >


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

	if (myCurrentBullCounter == myHiddenWord.length()) {
		return true;

	}

	return false;
}


//More stuff like booleans and void
void FBullCowGameOBJ::reset() {

	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = originalWord;
	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	myHiddenWord = HIDDEN_WORD;
	return;
}

EGuessInputStatus FBullCowGameOBJ::CheckGuessValidity(FString Guess) const {
	
	if (Guess == "rootExit") {
		return EGuessInputStatus::rootExit;
	}

	else if (Guess == "rootSetWord") {
		return EGuessInputStatus::rootSetWord;
	}

	if (false) {
		return EGuessInputStatus::Not_Isogramm;
	}
	else if (Guess.length() != getHiddenWordLenght()) {
		return EGuessInputStatus::Wrong_Lenght;
	}
	else if (false) {
		return EGuessInputStatus::Not_Lowercase;
	}
	else {

		return EGuessInputStatus::OK;
		
	}
}

// receives a VALID guess, increments turn and returns cows
FBullcowCount FBullCowGameOBJ::SubmitGuess(FString Guess) {

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
				
			}
		}

	}
	// This fix the error with the Cows counter that was happening inside of the foor loop 
	BullCowCount.Cows = hiddenWordLenght - BullCowCount.Bulls; // increment cows (doesn't match)
	myCurrentBullCounter = BullCowCount.Bulls;

	return BullCowCount;
}



FString FBullCowGameOBJ::setWord() {
	
	FString newWord;
	int32 CH;

	do {

		CH = _getwch();

		switch (CH) {

		case 13://enter
			std::cout << std::endl;
			break;

		case 8://backspace
			if (newWord.length() > 0) {
				newWord.erase(newWord.end() - 1); //remove last character from string
				std::cout << CH << ' ' << CH;//go back, write space over the character and back again.
			}
			break;

		default://regular ascii
			newWord += CH;//add to string
			std::cout << '*';//print `*`
			break;
		}

	} while (CH != 13);

	//print result:
	//std::cout << newWord << std::endl;
	myHiddenWord = newWord;

	return newWord;

 }

FString FBullCowGameOBJ::getFeedback() {  // TODO MAKE FULL FEEDBACK
	
	FString feedback = "";
	int32 Wlenght = FBullCowGameOBJ::getHiddenWordLenght();

	for (int32 idx = 0; idx < Wlenght; idx++)
	{
		feedback += "_";
	}

	return feedback;
}


bool FBullCowGameOBJ::isIsogram(FString) {
	return false;
}


