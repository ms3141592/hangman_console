// how everything is going to look in console

#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include<iostream>

#include "gamelogic.h"

using std::cout;
using std::endl;

class ConsoleDisplay {
private:
	GameLogic gamelogic;
	int _wrongGuessCount = 0;

public:
	void displayBlankWord();
	void displayGuessedLetters();
	void displayWrongGuessNum();
	void displayHangman();
};
// display "_" for unguessed letters
void ConsoleDisplay::displayBlankWord() {	
	string blankWord =  gamelogic.getBlankWord();
	if(!gamelogic.guessedWord()){
		cout << blankWord << endl;
	}
}

void ConsoleDisplay::displayGuessedLetters() {
	
	string guessedLetters;
	if(!gamelogic.killedMan()) {
		displayBlankWord();
		guessedLetters = gamelogic.getGuessedLetters();
		cout << guessedLetters << endl;
	}
	

	
	
}

void ConsoleDisplay::displayWrongGuessNum() {
	_wrongGuessCount = gamelogic.getWrongGuessNum();
	
	cout << _wrongGuessCount << endl;
}

void ConsoleDisplay::displayHangman() {
	string line;
	int num = 1;
	
	std::ifstream myfile("hangingman.txt");
	// print hangman from txt and location on txt
	while ( getline (myfile, line) ) {
	
		if(_wrongGuessCount == 0 && (num >= 1 && num <= 18) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 1 && (num >= 19 && num <= 36) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 2 && (num >= 37 && num <= 54) ) {	    
	    cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 3 && (num >= 55 && num <= 72) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 4 && (num >= 73 && num <= 90) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 5 && (num >= 91 && num <= 108) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 6 && (num >= 109 && num <= 126) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else if(_wrongGuessCount == 7 && (num >= 127 && num <= 144) ) {	    
	    	cout << line << endl;
	    	num++;
		}
		else {
			num++;
		}
	}
	myfile.close();
}
// display all guessed letters
// display hangman






#endif

