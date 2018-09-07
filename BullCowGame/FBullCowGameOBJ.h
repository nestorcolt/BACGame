#pragma once
#include <string>

using FString = std::string;
using int32 = int;

/*
Implement of struct - is like a class but will all memmbers public by default
*/

struct FBullcowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

//

enum class EGuessInputStatus {
	rootSetWord,
	rootExit,
	Invalid_Status,
	OK,
	Not_Isogramm,
	Wrong_Lenght,
	Not_Lowercase
};

 
class FBullCowGameOBJ{

public:

	FBullCowGameOBJ(); //Constructor

	FString myHiddenWord;
	int32 getMaxTries() const;
	int32 myCurrentTry;
	int32 getCurrentTry() const;
	int32 getHiddenWordLenght() const;
	
	//getWord >> will return User input word 
	FString setWord();
	FString getFeedback();

	bool isGameWom() const;
	void reset(); // TODO make a more rich value for return reset
	EGuessInputStatus CheckGuessValidity(FString) const; // TODO make a more rich value for return GuessValidity

	// counts bulls & cows and increases try #
	FBullcowCount SubmitGuess(FString);


private:
	
	int32 myMaxTries;
	int32 myCurrentBullCounter;
	FString originalWord = "plant";
	bool isIsogram(FString);

};

