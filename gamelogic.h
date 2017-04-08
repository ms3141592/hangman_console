// all logic

#ifndef GAMELOGIC_H
#define GAMELOGIC_H


#include "userinput.h"
#include "randomword.h"


class GameLogic {
private:
	RandomWord randomword; 
	UserInput userinput; 
	string _hiddenWord = randomword.getWord();  
	string _guessedLetters; 
	string _letterInWord;
	string _blankWord;
	int _guessedIncorrect = 0; 
	
	void guessLetter();  // keep track of _guessedLetters
	void setBlankWord();
	void updateBlankWord();
	void guessedWrong(string); // keep int of wrong guesses
public:
	
	string getBlankWord();
	string getGuessedLetters(); // return _guessedLetters
	int getWrongGuessNum();
	bool guessedWord();
	bool killedMan();
};

// user guessed letters
void GameLogic::guessLetter() {		

	bool alreadyGuessed = false;
	string letter = userinput.getString();

	for(int i = 0; i < _guessedLetters.length(); i++) {
		if(_guessedLetters[i] == letter[0]) {
			alreadyGuessed = true;
		}
	}
	
	if(!alreadyGuessed) {
		_guessedLetters.append(letter);
		guessedWrong(letter);
	}
}

void GameLogic::guessedWrong(string letter) {
	bool missedGuess = true;
	for(int i = 0; i < _hiddenWord.length(); i++) {
		if(_hiddenWord[i] == letter[0]) {
			missedGuess = false;
		}
	}
	if(missedGuess) {
		_guessedIncorrect++;
	}
}

void GameLogic::setBlankWord() {	
	for(int i = 0; i < _hiddenWord.length(); i++) {
		if(!isspace(_hiddenWord[i])) {
			_blankWord.append("-");
		}else{
			_blankWord.append(" ");
		}	
	}
}

void GameLogic::updateBlankWord() {
	for(int i = 0; i < _hiddenWord.length(); i++) {
		for(int j = 0; j < _guessedLetters.length(); j++) {
			if(_guessedLetters[j] == _hiddenWord[i]) {
				_blankWord[i] = _hiddenWord[i];
			}
		}
	}
}

string GameLogic::getBlankWord() {
	if(_blankWord.length() == 0) {
		setBlankWord();
	}
	updateBlankWord();
	return _blankWord;
}

string GameLogic::getGuessedLetters() {
	guessLetter();
	return _guessedLetters;
}

int GameLogic::getWrongGuessNum() {
	return _guessedIncorrect;
}

bool GameLogic::guessedWord() {
	bool guessed = false;
	if(_blankWord == _hiddenWord) {
		guessed = true;
	}
	return guessed;
}

bool GameLogic::killedMan() {
	bool dead = false;
	if(_guessedIncorrect == 7) {
		dead = true;
	}
	return dead;
}





#endif
