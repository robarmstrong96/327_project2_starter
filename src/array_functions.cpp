/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur

//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

//zero out array that tracks words and their occurrences
#include <cstring>
#include "array_functions.h"
#include "utilities.h"
using namespace std;
const string INIT_STRING = " ";

struct word_struct {
	word_struct(): word(INIT_STRING), references(constants::SUCCESS) {}
	word_struct(string word, int references): word(word), references(references) {}
	string word = INIT_STRING;
	int references = constants::SUCCESS;
} array_word[constants::MAX_WORDS];

void clearArray() {
	for (int i = 0; i < constants::MAX_WORDS - 1; i++) {
		array_word[i].word = INIT_STRING;
		array_word[i].references = constants::SUCCESS;
	}
	//array_word = new word[constants::MAX_WORDS];
}

//how many unique words are in array
int getArraySize() {
	int i;
	for (i = 0; array_word[i].references != constants::SUCCESS; i++);
	return i;
}

//get data at a particular location
std::string getArrayWordAt(int i) {
	return array_word[i].word;
}

int getArrayWord_NumbOccur_At(int i) {
	return array_word[i].references;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream) {
	if(myfstream.is_open() || !(myfstream.peek() == std::ifstream::traits_type::eof())) {
		string line;
		while(!myfstream.eof()) {
			getline(myfstream,line);
			if (line == "") { return false; }
			processLine(line);
		}
	  closeFile(myfstream);
		return true;
	}
	return false;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString) {
	stringstream temp(myString);
	string token;

	while (getline(temp, token, constants::CHAR_TO_SEARCH_FOR)) {


		processToken(token);
	}
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {
	int i;
	string temp = token;
	string temp_struct;
	toUpper(temp), strip_unwanted_chars(temp);
	for (i = 0; array_word[i].word != INIT_STRING; i++) {
		temp_struct = array_word[i].word, strip_unwanted_chars(temp_struct);
		toUpper(temp_struct);
		if (temp_struct.compare(temp) == constants::SUCCESS) {
			array_word[i].references++;
			return;
		}
	}
	if (strip_unwanted_chars(token)) {
		//word_struct temp = word_struct{token, 1};
		array_word[i] = word_struct{token, 1};
	}
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode) {
				myfile.open(myFileName.c_str(), mode);
				return myfile.is_open();
    }

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename) {
	fstream outputFile;
	outputFile.open(outputfilename.c_str(), std::fstream::out);
	string temp;
	for (int i = 0; i < getArraySize(); i++) {
		outputFile << array_word[i].word << ' ' << array_word[i].references << '\n';
	}
	closeFile(outputFile);
	return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {
	switch(so) {
		case constants::NONE:
			break;
		case constants::ASCENDING:
			for (int i = 0; i < getArraySize() - 1; i++) {
				for (int j = 0; j < getArraySize() - i - 1; j++) {
					if(array_word[j].word > array_word[j + 1].word) {
						word_struct temp = array_word[j];
						array_word[j] = array_word[j + 1];
						array_word[j + 1] = temp;
					}
				}
			}
			break;
		case constants::DESCENDING:
			for (int i = 0; i < getArraySize() - 1; i++) {
				for (int j = 0; j < getArraySize() - i - 1; j++) {
					if(array_word[j].word < array_word[j + 1].word) {
						word_struct temp = array_word[j];
						array_word[j] = array_word[j + 1];
						array_word[j + 1] = temp;
					}
				}
			}
			break;
		case constants::NUMBER_OCCURRENCES:
			for (int i = 0; i < getArraySize() - 1; i++) {
				for (int j = 0; j < getArraySize() - i - 1; j++) {
					if(array_word[j].references > array_word[j + 1].references) {
						word_struct temp = array_word[j];
						array_word[j] = array_word[j + 1];
						array_word[j + 1] = temp;
					}
				}
			}
			break;
	}
}
