#include<iostream>


#include "consoledisplay.h"




int main() {

	
	//	test
	while(true) {
		
		RandomWord randomword;
		UserInput userinput;
		char y = userinput.getChar();
		string x = randomword.getWord();
		std::cout << y << x << std::endl;
	
	}
	
	return 0;
}
