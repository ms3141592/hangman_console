#include<iostream>


#include "consoledisplay.h"




int main() {
	
	ConsoleDisplay consoledisplay;

	do {
		consoledisplay.displayGameScreen();
	} while (true);



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
