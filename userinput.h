// gets user input char, int, string

#ifndef USERINPUT_H
#define USERINPUT_H


#include<conio.h>
// check what key is pressed from user int and char 

class UserInput {
	
private:
	char _alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
						 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
						 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'	};
	char _store; // save char  
	int _keyNum; // key num	
	void getKeyboardInput(); // gets user input and stores it in keyNum
	void setChar();
public:
	char getChar(); // returns picked char
	
};

void UserInput::getKeyboardInput(){
	_keyNum = -1;
	while (_keyNum == -1) {	
		if (_kbhit()) {
			_keyNum = _getch();
		}
	}
	setChar();
}

void UserInput::setChar() {
	// CAPSLOCK
	if( ( _keyNum >= 65) && (_keyNum <= 90) ) {
		_store = _alphabet[_keyNum-65];
	}
	else if( ( _keyNum >= 97) && (_keyNum <= 122) ) {
		_store = _alphabet[_keyNum-97];
	} else { // did not enter the alphabet
		getKeyboardInput();
	}	
}

char UserInput::getChar(){
	getKeyboardInput();
	return _store;
}

#endif
