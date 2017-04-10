// how everything is going to look in console

#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include<algorithm>
//#include<iostream>
#include<windows.h>

#include "gamelogic.h"

using std::cout;
using std::endl;

class ConsoleDisplay {
private:
	GameLogic gamelogic;
	UserInput userinput;
	int _wrongGuessCount = 0;
	string _playAgain = "n";
	string _guessedLetters;
	
	void displayBlankWord();
	void displayLetters();
	void wrongGuessNum();
	void displayHangman();
	void coordinate(int,int);
	void guessLetter();
	void levelOver(string);
	void playAgain();
	void clearBackground();
public:	
	void displayGameScreen();
	void displayStartScree();
};

void ConsoleDisplay::coordinate(int x,int y) {
    COORD pos = {x,y};   
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ConsoleDisplay::clearBackground() {
	coordinate(0, 0);
	string line;
	std::ifstream myfile("fulldisplay.txt");
	while ( getline (myfile, line) ) {
	    cout << line << '\n';
	}	
}

// display "_" for unguessed letters
void ConsoleDisplay::displayBlankWord() {	
	coordinate(3, 10);	
	cout << gamelogic.getBlankWord() << endl;
}

void ConsoleDisplay::guessLetter() {
	_guessedLetters = gamelogic.getGuessedLetters();
}

void ConsoleDisplay::displayLetters() {
	sort(_guessedLetters.begin(), _guessedLetters.end());
	int xpos = 3, ypos = 5;
	
	coordinate(xpos, ypos);
	cout << "guessed letters:";
	ypos++;
	for(int i = 0; i < _guessedLetters.length(); i++) {
		if(i % 8 == 0) {
			ypos++;
			xpos = 3;
		}
		coordinate(xpos, ypos);
		cout << _guessedLetters[i] << ",";
		xpos += 2;	
	}
}

void ConsoleDisplay::wrongGuessNum() {
	_wrongGuessCount = gamelogic.getWrongGuessNum();
}

void ConsoleDisplay::displayHangman() {
	string line;
	int xpos = 34, ypos = 4;	
	int num = 1;
	
	std::ifstream myfile("hangingman.txt");
	// print hangman from txt and location on txt
	while ( getline (myfile, line) ) {
	
		if(_wrongGuessCount == 0 && (num >= 1 && num <= 18) ) {
			coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 1 && (num >= 19 && num <= 36) ) {	    
	    	coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 2 && (num >= 37 && num <= 54) ) {	    
		    coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 3 && (num >= 55 && num <= 72) ) {	    
	    	coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 4 && (num >= 73 && num <= 90) ) {	    
	    	coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 5 && (num >= 91 && num <= 108) ) {	    
	    	coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 6 && (num >= 109 && num <= 126) ) {	    
	    coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else if(_wrongGuessCount == 7 && (num >= 127 && num <= 144) ) {	    
	    	coordinate(xpos, ypos); 
	    	cout << line << endl;
	    	ypos++;
	    	num++;
		}
		else {
			num++;
		}
	}
	myfile.close();
}

void ConsoleDisplay::playAgain() {
	coordinate(3, 17);
	cout << "play again? ";
	_playAgain = userinput.getString();
	if(_playAgain=="y") {
        _guessedLetters.clear();
	}
	gamelogic.newGame(_playAgain);
 
}

void ConsoleDisplay::levelOver(string winorlose) {
	clearBackground();
	wrongGuessNum();
	displayHangman();
	coordinate(3, 13);
	cout << winorlose << endl;
	displayBlankWord();
	playAgain();
}

void ConsoleDisplay::displayGameScreen() {		
	gamelogic.getHiddenWord();
	
	while(!gamelogic.killedMan() && !gamelogic.guessedWord()) {
		clearBackground();
		wrongGuessNum();	
		displayHangman();
		displayLetters();
		displayBlankWord();
		guessLetter();

	}
	if(gamelogic.guessedWord()) {
		levelOver("you guessed correct!");

	} else if(gamelogic.killedMan()) {
		levelOver("you killed him");		
	} 
	
	
}
// display all guessed letters
// display hangman





#endif

