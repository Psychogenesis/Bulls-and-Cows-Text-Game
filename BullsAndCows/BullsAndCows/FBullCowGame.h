#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowsCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	NOT_ISOGRAM,
	ALLREADY_TRIED,
	WRONG_LENGTH,
	CONTAINS_NUMBERS,
	CONTAINS_SPECIAL_SYMBOLS,
	MORE_THAN_1_WORD,
	INVALID
};

class FBullCowGame 
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon(FString) const;
	EGuessStatus IsValidGuess(FString) const;

	void SetMaxTries(int32);
	void Reset();
	void SetNewWord();	
	
	FBullCowsCount SubmitGuess(FString);

private:
	int32 mMyCurrentTry, mMyMaxTries;
	FString mHiddenWord; 
	bool IsIsogram(FString) const;
	bool IsContainsDigits(FString) const;
	bool IsContainsSpecialChars(FString) const;
};
