// picks random word from txt

#ifndef RANDOMWORD_H
#define RANDOMWORD_H


#include<fstream>
#include<string>
#include<time.h>

using std::string;


class RandomWord {
private:
	int _fileLen = 20; // set the length of the items in "words.txt" file
	string _randomWord; // place holder for new word
	
	int randomNum(); // random num generator uses _fileLen
	void randomLine(); // uses randomNum() to get a word from ".txt" file
public:
	string getWord(); // uses randomLine() and returns randomWord
};

int RandomWord::randomNum() {
	srand(time(0));
	int num = rand()%_fileLen;	
	return num;
}

void RandomWord::randomLine() {
	string line;
	int num = randomNum();
	std::ifstream myfile("words.txt");
	
	// loop through each line of ".txt"
	for(int i = 0; i < _fileLen && getline(myfile, line); i++) {
		// when randon number is reached stop and use word
		if(i == num) { 
			_randomWord = line;
			break;
		}
	}
	myfile.close();		
}

string RandomWord::getWord() {
	randomLine();
	return _randomWord;
}

#endif
