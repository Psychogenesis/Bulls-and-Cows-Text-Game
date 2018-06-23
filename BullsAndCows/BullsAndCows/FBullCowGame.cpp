#include "FBullCowGame.h"


//getters
int32 FBullCowGame::GetMaxTries() const { return mMyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return mMyCurrentTry; }

//setters
void FBullCowGame::SetMaxTries(int32 value) { mMyMaxTries = value; }

FBullCowGame::FBullCowGame() { Reset(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	mMyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "dupa";
	mHiddenWord = HIDDEN_WORD;

	mMyCurrentTry = 1;
	return;
} 

bool FBullCowGame::IsGameWon(FString word) const { return (word == mHiddenWord); }

void FBullCowGame::SetNewWord()
{
}

bool FBullCowGame::IsValidGuess(FString word)
{
	return false;
}

bool FBullCowGame::IsIsogram()
{
	return false;
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