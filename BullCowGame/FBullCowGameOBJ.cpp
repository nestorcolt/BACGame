#pragma once
#include "FBullCowGameOBJ.h"
#include <stdio.h>
#include <iostream>
#include < conio.h >
#include <map>
// #define is like using, replace one thing from the other
#define TMap std::map

using int32 = int;

//Constructor
FBullCowGameOBJ::FBullCowGameOBJ() {
	reset();
}

//Integer methods 
int32 FBullCowGameOBJ::getCurrentTry() const{return myCurrentTry;}
int32 FBullCowGameOBJ::getHiddenWordLenght() const {return myHiddenWord.length();}


int32 FBullCowGameOBJ::getDificulty() const{

	int32 level;
	int32 NM;
	std::cout << "Chose a level between  [1] - [2] - [3] : ";
	
	std::cin >> NM;
	std::cin.get();

	switch (NM) {
	
	case 3:
		level = 1;
		break;

	case 2:
		level = 2;
		break;

	default:
		level = 3;
		break;
	
	}

	std::cout << std::endl;

	return level;
}

bool FBullCowGameOBJ::isGameWom() const {
	if (myCurrentBullCounter == myHiddenWord.length()) {
		return true;

	}
	return false;
}

int32 FBullCowGameOBJ::getMaxTries(int32 level) const { 
	
	int32 wordLenght = FBullCowGameOBJ::getHiddenWordLenght();
	int32 levelCal = FBullCowGameOBJ::doCalculate(level);
	TMap<int32, int32> wordLengthToMaxTries{ {wordLenght,levelCal}};
	return wordLengthToMaxTries[wordLenght];

}


//More stuff like booleans and void
void FBullCowGameOBJ::reset() {

	myCurrentTry = 1;
	myHiddenWord = originalWord;
	return;
}

EGuessInputStatus FBullCowGameOBJ::CheckGuessValidity(FString Guess) const {

	if (Guess == "rootExit") {
		return EGuessInputStatus::rootExit;
	}

	else if (Guess == "rootSetWord") {
		return EGuessInputStatus::rootSetWord;
	}

	if (!isIsogram(Guess)) {
		return EGuessInputStatus::Not_Isogramm;
	}
	else if (Guess.length() != getHiddenWordLenght()) {
		return EGuessInputStatus::Wrong_Lenght;
	}
	else if (!isLowercase(Guess)) {
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

	FBullCowGameOBJ::currentGuess = Guess;

	return BullCowCount;
}

int32 FBullCowGameOBJ::doCalculate(int32 value) const{
	int32 result;
	result = int(ceil(FBullCowGameOBJ::getHiddenWordLenght() * value ));
	return result;
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


bool FBullCowGameOBJ::isIsogram(FString word) const{

	// treat 0 and 1 letter words as isograms
	if (word.length() <= 1) { return true; }
	
	//setup tmap
	TMap<char, bool> LetterSeen;

	////loop thorught all the letters of the word
	for (auto letter : word){
		//	if the letter is in the map	
		letter = tolower(letter);

		if (LetterSeen[letter]) {
			//	we do NOT have an isIsogram
			return false;
		}
		else {
			//	add the letter tho the map
			LetterSeen[letter] = true;
		}
	
	}

	return true;
}

bool FBullCowGameOBJ::isLowercase(FString word) const {

	for (auto letter : word) {
		if (isupper(letter)) {
			return false;
		}
	}

	return true;
}


FString FBullCowGameOBJ::getFeedback() {  

	FString Guess = currentGuess;  //Incoming word

	//If is first try make guess spaces in word as hidden word
	if (myCurrentTry == 1) { Guess = myHiddenWord; }

	FString feedback;
	char underscore = '_';

	//Logic
	FString word = myHiddenWord;
	int wordLenght = Guess.length();

	FString wordLettersArray(wordLenght, '_');
	int arr_lenght = sizeof(wordLettersArray);


	for (int idx = 0; idx < wordLenght; idx++)
	{
		if (myCurrentTry == 1) {
			wordLettersArray[idx] = underscore;
		}
		
		else if (Guess[idx] == word[idx]){
			wordLettersArray[idx] = word[idx];
		}
	}

	feedback = wordLettersArray;

	return feedback;
}

