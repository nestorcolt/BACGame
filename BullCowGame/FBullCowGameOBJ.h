#pragma once
#include <string>

class FBullCowGameOBJ{

public:

	FBullCowGameOBJ(); //Constructor

	void reset(); // to improve
	int getMaxTries() const;
	int getCurrentTry() const;
	//getWord >> will return User input word 
	std::string getWord();
	bool isGameWom() const;


private:
	int myCurrentTry;
	int myMaxTries;
	bool isIsogram(std::string);
};

