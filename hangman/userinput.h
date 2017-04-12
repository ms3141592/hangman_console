// gets user input char, int, string

#ifndef USERINPUT_H
#define USERINPUT_H


#include<conio.h>
#include<string>

using std::string;
// check what key is pressed from user int and char 

class UserInput {
	
private:
	string _alphabet = "abcdefghijklmnopqrstuvwxyz";
	string _storeLetter; // save letter  
	int _keyNum; // keyboard input num	
	void getKeyboardInput(); // gets user input and stores it in _keyNum
	void setString(); // checks for input and returs alphabet only
public:
	string getString(); // returns picked char	
};

void UserInput::getKeyboardInput(){
	_keyNum = -1;
	while (_keyNum == -1) {	
		if (_kbhit()) {
			_keyNum = _getch();
		}
	}
	setString();
}

void UserInput::setString() {
	// CAPSLOCK key numbers
	if( ( _keyNum >= 65) && (_keyNum <= 90) ) {
		_storeLetter = _alphabet[_keyNum-65];
	} // lowercase
	else if( ( _keyNum >= 97) && (_keyNum <= 122) ) {
		_storeLetter = _alphabet[_keyNum-97];
	} else { // did not enter the alphabet
		getKeyboardInput();
	}	
}

string UserInput::getString(){
	getKeyboardInput();
	return _storeLetter;
}

#endif
