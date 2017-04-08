// all logic

#ifndef GAMELOGIC_H
#define GAMELOGIC_H


#include "userinput.h"
#include "randomword.h"


class GameLogic {
private:
	RandomWord randomword; 
	UserInput userinput; 
	string _hiddenWord;  
	string _guessedLetters; 
	string _letterInWord;
	string _blankWord;
	int _guessedIncorrect = 0; 
	
	void guessLetter();  // keep track of _guessedLetters
	
public:
	string getHiddenWord();
	string getBlankWord();
	string getGuessedLetters(); // return _guessedLetters
	
	
};

// user guessed letters
void GameLogic::guessLetter() {
	string letter = userinput.getString();
	_guessedLetters.append(letter);
	
	//for(int i = 0; i < _hiddenWord.length(); i++) {
	if(!_hiddenWord.find(letter)) {
		_guessedIncorrect++;
	}
	
	
	//}
}

string GameLogic::getHiddenWord() {	
	for(int i = 0; i < _hiddenWord.length(); i++) {
		if(!isspace(_hiddenWord[i])) {
			_blankWord.append("-");
		}else{
			_blankWord.append(" ");
		}
		
		for(int j = 0; j < _guessedLetters.length(); j++) {
			if(_guessedLetters[j] == _hiddenWord[i]) {
				_blankWord[i] = _hiddenWord[i];
			}
		}
	}
	
	return _hiddenWord;
}

string GameLogic::getBlankWord() {
	_hiddenWord = randomword.getWord();
	getHiddenWord();
	return _blankWord;
}


// user guessed correct
// user guessed incorrect






#endif
