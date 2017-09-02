#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void Intro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();


bool AskToPlayAgain();

FBullCowGame BCGame; // instance of the new game

int main()
{
	bool bPlayAgain = false;
	do {
		Intro();
		PlayGame();
		bPlayAgain=AskToPlayAgain();
		}
	while (bPlayAgain);
	return 0;
}

void PlayGame()
{
	//loop the turns 	
	BCGame.Reset();	//creates an instance of a game 
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		//std::cout << MaxTries <<std::endl;
		
			FText Guess = GetValidGuess();

		//	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << " Cows = " << BullCowCount.Cows << std::endl;

			std::cout << std::endl;
			
	}PrintGameSummary();
}
bool AskToPlayAgain()
{
	//checks if player wants to repeat the game
	std::cout << "Do you want to play again with the same word? (y/n)\n";
	FText Answer = "";
	std::getline(std::cin, Answer);
	std::cout << std::endl;
	return (Answer[0] == 'Y') || (Answer[0] == 'y');
}

FText GetValidGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		
		std::cout << "Try " << CurrentTry << ". Take a guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "entered word is not an isogram, please enter an isogram";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "please enter only lowercase letters";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void Intro()
{
	// displays an intro to the game

	std::cout << "\n \nWelcome to Bulls and Cows\n";
	std::cout << "Guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of\n";
	std::cout << std::endl;
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done - you win!\n";
	}
	else
	{
		std::cout << "You lose, better luck next time\n";
	
	}
}
