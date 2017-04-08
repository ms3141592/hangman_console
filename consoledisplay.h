// how everything is going to look in console

#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include<iostream>

#include "gamelogic.h"


class ConsoleDisplay {
private:
	GameLogic gamelogic;
	string _guessedLetters;
	
public:
	void displayBlankWord();
};
// display "_" for unguessed letters
void ConsoleDisplay::displayBlankWord() {
	string word =  gamelogic.getHiddenWord();
	string blankWord =  gamelogic.getBlankWord();
	std::cout << word << std::endl;
	std::cout << blankWord << std::endl;
}
// display all guessed letters
// display hangman






#endif

