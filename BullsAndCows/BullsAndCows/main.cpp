#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
void GameLoop();
void PrintBack(string Guess);

// the entry point for our application
int main()
{
	PrintIntro();
	GameLoop();

	cout << endl;
	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << endl;
	return;
}

void GameLoop()
{
	bool GameFinished = false;
	string ExitWord = "dupa";
	string guess;

	while (!GameFinished)
	{
		guess = GetGuess();
		PrintBack(guess);
		if (guess == ExitWord)
		{
			GameFinished = true;
		}
	}
}

// get a guess from the player
string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;	
}

void PrintBack(string Guess)
{
	// print the guess back
	cout << "Your guess was: " << Guess << endl;
	return;
}

//Just a test