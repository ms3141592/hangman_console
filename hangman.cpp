#include<iostream>


#include "consoledisplay.h"




int main() {
	
	ConsoleDisplay consoledisplay;
	while(true) {

	consoledisplay.displayHangman();
	
	//consoledisplay.displayBlankWord();

	consoledisplay.displayGuessedLetters();

	consoledisplay.displayWrongGuessNum();

	}
	/*	test
	while(true) {
		
		RandomWord randomword;
		UserInput userinput;
		string y = userinput.getString();
		string x = randomword.getWord();
		std::cout << y << x << std::endl;
	
	}*/
	
	return 0;
}
