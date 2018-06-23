#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowsCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon(FString) const;

	void SetMaxTries(int32);
	void Reset();
	void SetNewWord();	
	bool IsValidGuess(FString);
	FBullCowsCount SubmitGuess(FString);

private:
	int32 mMyCurrentTry, mMyMaxTries;
	FString mHiddenWord; 
	bool IsIsogram();
};
