#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool IsPalyngAgain();
/*int32 PlayerTriesAmmount(int32 ammount);*/

FBullCowGame BCGame;

// the entry point for our application
int main()
{
	bool _isPlayingAgain = false;

	PrintIntro();
	do 
	{
		PlayGame();
		_isPlayingAgain = IsPalyngAgain();
	} while (_isPlayingAgain);
	

	std::cout << std::endl;

	system("Pause");
	return 0;
}

void PlayGame()
{	
	FText guess;
	
 	BCGame.Reset(); 

	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 1; i <= MaxTries; i++)
	{
		guess = GetValidGuess();
		FBullCowsCount BullCowCount = BCGame.SubmitGuess(guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
		if (BCGame.IsGameWon(guess))
		{
			std::cout << "Congratulations! You've won!" << std::endl;
			return;
		}				
	}
	return;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

int32 PlayerTriesAmmount()
{
	int32 ammount;
	std::cout << "How many tries you want to get?" << std::endl;
	std::cout << "Enter number of tries: ";
	std::cin >> ammount;
	std::cout << std::endl;
	return ammount;
}

FText GetValidGuess()
{
	FText Guess;
	EGuessStatus status;
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". ";

	do 
	{
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		status = BCGame.IsValidGuess(Guess);

		switch (status)
		{
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::CONTAINS_NUMBERS:
			std::cout << "No numbers are allowed.\n";
			break;
		case EGuessStatus::CONTAINS_SPECIAL_SYMBOLS:
			std::cout << "only letters are allowed.\n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "The word must be an isogram.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (status != EGuessStatus::OK);
	
}

bool IsPalyngAgain()
{
	FText Responce;
	std::cout << "Do you want to play again? (y/n)" << std::endl;
	std::getline(std::cin, Responce);
	return (tolower(Responce[0]) == 'y');
}
