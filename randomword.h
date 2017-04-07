// picks random word from txt

#ifndef RANDOMWORD_H
#define RANDOMWORD_H


#include<fstream>
#include<string>
#include<time.h>

using std::string;


class WordFromFile {
private:
	int fileLen = 5; // set the length of the items in ".txt" file
	string _randomWord; // place holder for new word
	
	int randomNum(); // random num generator uses fileLen
	void randomLine(); // uses randomNum() to get a word from ".txt" file
public:
	string getWord(); // uses randomLine() and returns randomWord
};

int WordFromFile::randomNum() {
	srand(time(0));
	int num = rand()%fileLen;	
	return num;
}

void WordFromFile::randomLine() {
	string line;
	int num = randomNum();
	std::ifstream myfile("sample.txt");
	
	// loop through each line of ".txt"
	for(int i = 0; i < fileLen && getline(myfile, line); i++) {
		// when randon number is reached stop and use word
		if(i == num) { 
			_randomWord = line;
			break;
		}
	}
	myfile.close();		
}

string WordFromFile::getWord() {
	randomLine();
	return _randomWord;
}

#endif
