#include "FBullCowGame.h"

//constructor
FBullCowGame::FBullCowGame() { Reset(); }

//getters
int32 FBullCowGame::GetMaxTries() const { return mMyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return mMyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return mHiddenWord.length(); }

//setters
void FBullCowGame::SetMaxTries(int32 value) { mMyMaxTries = value; }

bool FBullCowGame::IsGameWon(FString word) const { return (word == mHiddenWord); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "earth";

	mMyMaxTries = MAX_TRIES;
	mHiddenWord = HIDDEN_WORD;
	mMyCurrentTry = 1;

	return;
} 

void FBullCowGame::SetNewWord()
{
}

EGuessStatus FBullCowGame::IsValidGuess(FString word, std::vector <FString> GuessArray) const
{
	if (word.length() != GetHiddenWordLength())
		return EGuessStatus::WRONG_LENGTH;
	else if (IsNotAWord(word))
		return EGuessStatus::NOT_A_WORD;
	else if (IsNotIsogram(word))
		return EGuessStatus::NOT_ISOGRAM;
	else if (IsNot1Word(word))
		return EGuessStatus::MORE_THAN_1_WORD;
	else if (IsAlreadyTried(word, GuessArray))
		return EGuessStatus::ALREADY_TRIED;
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

#pragma region Helpers

bool FBullCowGame::IsNotAWord(FString guess) const { return (FString::npos != guess.find_first_of("0123456789")); }

bool FBullCowGame::IsNotIsogram(FString word) const
{
	for (int32 i = 0; i < word.length(); i++)
	{
		for (int32 j = i + 1; j <= word.length(); j++)
		{
			if (word[i] == word[j])
				return true;
		}
	}
	return false;
}

bool FBullCowGame::IsNot1Word(FString guess) const
{
	for (char c : guess)
	{
		if (c == ' ')
			return true;
	}
	return false;
}

bool FBullCowGame::IsAlreadyTried(FString guess, std::vector <FString> GuessArray) const
{
	if (!GuessArray.empty())
	{
		for (int32 i = 0; i < GuessArray.size(); i++)
			if (guess == GuessArray[i])
				return true;
	}
	return false;	
}
#pragma endregion





