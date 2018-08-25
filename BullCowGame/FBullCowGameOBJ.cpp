#include "FBullCowGameOBJ.h"

//Constructor
FBullCowGameOBJ::FBullCowGameOBJ() {
	reset();
}

//Integer methods 
int FBullCowGameOBJ::getMaxTries() const {return myMaxTries;}
int FBullCowGameOBJ::getCurrentTry() const{return myCurrentTry;}

bool FBullCowGameOBJ::isGameWom() const {
	return false;
}



//More stuff like booleans and void
void FBullCowGameOBJ::reset() {
	myCurrentTry = 1;
	myMaxTries = 5;
	return;
}


std::string FBullCowGameOBJ::getWord() {
	return std::string();
 }


bool FBullCowGameOBJ::isIsogram(std::string) {
	return false;
}


