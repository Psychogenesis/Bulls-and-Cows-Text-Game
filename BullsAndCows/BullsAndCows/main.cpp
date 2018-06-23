#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetGuess();
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
		guess = GetGuess();
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
	constexpr int32 WORLD_LENGTH = 4;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
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

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess;
	std::getline(std::cin, Guess);
	return Guess;	
}

bool IsPalyngAgain()
{
	FText Responce;
	std::cout << "Do you want to play again? (y/n)" << std::endl;
	std::getline(std::cin, Responce);
	return (tolower(Responce[0]) == 'y');
}
