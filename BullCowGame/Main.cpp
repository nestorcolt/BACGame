/*
This is the console executable that makes use of the bullCob class 
this acts as the view in a MVC patterns, and is responsable for all
user interacion. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGameOBJ.h"



//----------------------------

using FText = std::string;
using int32 = int;

// Code Colt in C++
//
//Globals:
constexpr int32	number_of_turns = 5;
// 
void PrintIntro();
void playGame();
FText GetGuess();
bool playAgain();

// first instantiation
FBullCowGameOBJ BCGame;

// --------------------------------------------------------------------------------------------------------

// the entry point to the application

/*
int main(){

	bool playAgainCheck = true;


	while (playAgainCheck == true) {
		// prints intro and welcome to the game
		PrintIntro();

		// execute game
		playGame();

		// retry game
		playAgainCheck = playAgain();

	

	}


	return 0;

} 
*/



int main(){


	bool playAgainCheck = true;

	do {

			// prints intro and welcome to the game
			PrintIntro();

			// execute game
			playGame();

			// retry game
			playAgainCheck = playAgain();

	}

	while (playAgainCheck == true);
	return 0;

} 




void playGame(){

	int32 maxTries = BCGame.getMaxTries();

	// loop getting guesses
	for (int32 idx = 1; idx <= maxTries; idx++) {

		FText Guess = GetGuess(); 

		if (Guess == "rootExit") {
			return;

			}

		//Submit valid guess 
		FBullcowCount bullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "  - Bulls =  " << bullCowCount.Bulls << std::endl;
		std::cout << "  - Cows  =  " << bullCowCount.Cows << std::endl;
		std::cout << std::endl;

		if (BCGame.isGameWom()) {
			Guess = BCGame.myHiddenWord;
			std::cout << " - CONGRATULATIONS YOU'VE WON !!! \n\n";

			return;
		}
	}

	// TODO sumarise game.

}


// get a guess from the player
FText GetGuess() {

	FText Guess;
	EGuessInputStatus Status = EGuessInputStatus::Invalid_Status;

	do {

		int32 currentTry = BCGame.getCurrentTry();

		std::cout << "Try: " << currentTry;
		std::cout << " + (" << BCGame.getFeedback() <<") + ";
		std::cout << " Type a " << BCGame.getHiddenWordLenght() << " Letters Word: ";
		std::getline(std::cin, Guess);
		

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {

		case EGuessInputStatus::rootSetWord:
			BCGame.setWord();
			std::cout << " - Hidden word changed - " << std::endl;
			break;

		case EGuessInputStatus::rootExit:
			std::cout << "Exiting Game ...\n";
			std::cout << std::endl;
			return Guess;
			
		case EGuessInputStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCGame.getHiddenWordLenght() << " letter word\n";
			BCGame.myCurrentTry++;
			break;

		case EGuessInputStatus::Not_Isogramm:
			std::cout << "Entered word isn't a Isogram, please try again\n";
			BCGame.myCurrentTry++;
			break;

		case EGuessInputStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters\n";
			BCGame.myCurrentTry++;
			break;

		default:
			BCGame.myCurrentTry++;
			break;
			
		}
		
	std::cout << std::endl;
	} while (Status != EGuessInputStatus::OK);
	

	return Guess;
}

bool playAgain() {

	std::cout << std::endl;
	std::cout << "Do you want to play again?" << std::endl;
	std::cout << "Type [yes] or [no]" << std::endl;

	FText response;
	std::getline(std::cin, response);

	if (response == "yes" || "no") {

		if (response == "yes") {
			BCGame.reset();

			return true;
		}

		else {
			std::cout << std::endl;
			return false;
		}

	}

	else {
		std::cout << "Please just type yes or no\n";
		playAgain();

	}

	return false;
}



// Introduce the game to the user
void PrintIntro() {	

	
	std::cout << std::endl;
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the isogram word I'm thinking of? \n\n\n";

	return; 
}