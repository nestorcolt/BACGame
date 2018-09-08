#pragma once
#include <string>

using FString = std::string;
using int32 = int;

/*
Implement of struct - is like a class but will have all memmbers public by default
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
	int32 getMaxTries(int32 level) const;
	int32 myCurrentTry;
	int32 getCurrentTry() const;
	int32 getHiddenWordLenght() const;
	int32 myMaxTries = 10;
	
	//getWord >> will return User input word 
	FString setWord();
	FString getFeedback();
	int32 getDificulty() const;


	bool isGameWom() const;
	void reset(); // TODO make a more rich value for return reset and select qhwn to reset with command
	EGuessInputStatus CheckGuessValidity(FString) const; 

	// counts bulls & cows and increases try #
	FBullcowCount SubmitGuess(FString);


private:
	//aqui esta el error
	int32 doCalculate(int32 value) const;
	int32 myCurrentBullCounter;
	FString originalWord = "plant";
	FString currentGuess;

	bool isIsogram(FString) const;
	bool isLowercase(FString) const;

};

