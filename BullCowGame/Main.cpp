#include <iostream>
#include <string>
#include "FBullCowGameOBJ.h"

// Code Colt in C++
//
//Globals:
constexpr int	number_of_turns = 5;
// 
void PrintIntro();
void playGame();
std::string GetGuess();
bool playAgain();

// first instantiation
FBullCowGameOBJ BCGame;

// --------------------------------------------------------------------------------------------------------

// the entry point to the application

//int main(){
//
//	bool playAgainCheck = true;
//

	//while (playAgainCheck == true) {
	//	// prints intro and welcome to the game
	//	PrintIntro();

	//	// execute game
	//	playGame();

	//	// retry game
	//	playAgainCheck = playAgain();

//	
//
//	}
//
//
//	return 0;
//
//} 




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
	
	std::cout << "Exiting Game 3 2 1  .." << std::endl;

	return 0;

	

} 




void playGame(){

	int maxTries = BCGame.getMaxTries();

	// loop getting guesses
	for (int idx = 1; idx <= maxTries; idx++) {

		std::string Guess = GetGuess();

		if (Guess == "rootExit") {
			return;
		}

		std::cout << "Player " << Guess << " Ready to start! \n" << std::endl;
		std::cout << std::endl;

	}

}


// get a guess from the player
std::string GetGuess() {

	int currentTry = BCGame.getCurrentTry();

	std::string Guess;
	std::cout << "Player name: ";
	std::getline(std::cin, Guess);
	return Guess;

}

bool playAgain() {

	std::cout << "Do you want to play again?" << std::endl;
	std::cout << "Type [yes] or [no]" << std::endl;

	std::string response;
	std::getline(std::cin, response);

	if (response == "yes" || "no") {

		if (response == "yes") {
			BCGame.reset();

			return true;
		}

		else {
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

	std::cout << "Welcome to Bulls and Cows\n" << std::endl;
	std::cout << "Can you guess the  " << number_of_turns;
	std::cout << " letter isogram I'm thinking of? \n\n";
	return; 
}