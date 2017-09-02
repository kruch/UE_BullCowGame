#include "FBullCowGame.h"
#include <map>
#define TMap std::map 


FBullCowGame::FBullCowGame(){Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length()!=GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	bGameIsWon = false;
}

//receives valid guess, increments 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++; 
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length(); //assuming same length

	//looping through letters in the hidden word
	for (int32 MHWChar = 0;MHWChar < WordLength; MHWChar++) 
	{	//compare letters agains the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++){
			if (Guess[GChar] == MyHiddenWord[MHWChar]) //if the letters match 
			{
				if (MHWChar == GChar){ //if letters are in the same place
				BullCowCount.Bulls++; 
				}else{
				BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter strings as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup map
	for(char Letter : Word)
	{
		Letter = tolower(Letter);

	}


	//loop all letters of the word

		//if the letter is in the map
			// not an isogram

		// else
			// add the letter to the map as seen

	return true;	// for ex in cases where /0 is entered
}

