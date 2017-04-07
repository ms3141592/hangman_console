#include<iostream>


#include "consoledisplay.h"




int main() {

	
	//	test
	WordFromFile wordfile;
	InputFromUser userinput;
	char y = userinput.getChar();
	string x = wordfile.getWord();
	std::cout << y << x;
	
	return 0;
}
