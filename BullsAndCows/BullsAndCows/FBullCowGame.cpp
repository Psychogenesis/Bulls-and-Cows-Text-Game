#include "FBullCowGame.h"

//constructor
FBullCowGame::FBullCowGame() { Reset(); }

//getters
int32 FBullCowGame::GetMaxTries() const { return mMyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return mMyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return mHiddenWord.length(); }

//setters
void FBullCowGame::SetMaxTries(int32 value) { mMyMaxTries = value; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "earth";

	mMyMaxTries = MAX_TRIES;
	mHiddenWord = HIDDEN_WORD;
	mMyCurrentTry = 1;

	return;
} 

bool FBullCowGame::IsGameWon(FString word) const { return (word == mHiddenWord); }
bool FBullCowGame::IsContainsDigits(FString guess) const { return (guess.begin(), guess.end(), ::isdigit); }

bool FBullCowGame::IsContainsSpecialChars(FString word) const
{
	return ((word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) != FString::npos);
}

void FBullCowGame::SetNewWord()
{
}

EGuessStatus FBullCowGame::IsValidGuess(FString word) const //TODO Make actual method
{
	if (word.length() != GetHiddenWordLength())
		return EGuessStatus::WRONG_LENGTH;
	else if (!IsIsogram(word))
		return EGuessStatus::NOT_ISOGRAM;
	else if (IsContainsDigits(word))
		return EGuessStatus::CONTAINS_NUMBERS;
	else if (IsContainsSpecialChars(word))
		return EGuessStatus::CONTAINS_SPECIAL_SYMBOLS;
	else
		return EGuessStatus::OK;
}

FBullCowsCount FBullCowGame::SubmitGuess(FString guess)
{
	mMyCurrentTry++;
	FBullCowsCount BullCowCount;

	int32 HiddenWordLength = mHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (guess[j] == mHiddenWord[i])
			{
				if (i == j)
					BullCowCount.Bulls++;
				else
					BullCowCount.Cows++;
			}			
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString word) const
{
	for (int32 i = 0; i < word.length(); i++)
	{
		for (int32 j = i + 1; j <= word.length(); j++)
		{
			if (word[i] == word[j])
				return false;
		}
	}
	return true;
}


