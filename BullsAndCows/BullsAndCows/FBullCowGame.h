#pragma once
#include <string>
#include <vector>

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
	ALREADY_TRIED,
	WRONG_LENGTH,
	NOT_A_WORD,
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
	EGuessStatus IsValidGuess(FString, std::vector <FString>) const;

	void SetMaxTries(int32);
	void Reset();
	void SetNewWord();	
	
	FBullCowsCount SubmitGuess(FString);

private:
	int32 mMyCurrentTry, mMyMaxTries;
	FString mHiddenWord; 
	bool IsNotIsogram(FString) const;
	bool IsNotAWord(FString) const;
	bool IsNot1Word(FString) const;
	bool IsAlreadyTried(FString, std::vector <FString>) const;
};
