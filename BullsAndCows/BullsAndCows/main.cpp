#include <iostream>
#include <string>
#include <vector>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool IsPalyngAgain();
/*int32 PlayerTriesAmmount(int32 ammount);*/

FBullCowGame BCGame;
std::vector <FString> GuessArray;

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
		status = BCGame.IsValidGuess(Guess, GuessArray);
		GuessArray.push_back(Guess);

		switch (status)
		{
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::NOT_A_WORD:
			std::cout << "This is not a word.\n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "The word must be an isogram.\n";
			break;
		case EGuessStatus::MORE_THAN_1_WORD:
			std::cout << "There must be only 1 word.\n";
			break;
		case EGuessStatus::ALREADY_TRIED:
			std::cout << "You've already tried this word. Put something different.\n";
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
