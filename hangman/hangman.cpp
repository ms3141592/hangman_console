#include<iostream>

#include "consoledisplay.h"

int main() {
	
	ConsoleDisplay consoledisplay;

	do {
		while (consoledisplay._startGame != "s" && consoledisplay._startGame != "c") {
			consoledisplay.displayStartScreen();
		}
		if (consoledisplay._playAgain == "y"){
			consoledisplay.displayGameScreen();
		}		
	} while (consoledisplay._startGame != "c");

	return 0;
}
