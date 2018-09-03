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

 
class FBullCowGameOBJ{

public:

	FBullCowGameOBJ(); //Constructor

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLenght() const;
	
	//getWord >> will return User input word 
	FString getWord();

	bool isGameWom() const;
	void reset(); // TODO make a more rich value for return 
	bool CheckGuessValidity(FString) const;

	// counts bulls & cows and increases try #
	FBullcowCount SubmitGuess(FString);


private:
	int32 myCurrentTry;
	int32 myMaxTries;
	bool isIsogram(FString);
	FString myHiddenWord;
};

