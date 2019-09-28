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
const string DELIM = " ";

struct word {
	string word = DELIM;
	int references = constants::SUCCESS;
} array_word[constants::MAX_WORDS];

string file_contents;

void clearArray() {
	for (int i = 0; i < array_word.length(); i++) {
		array_word[i].word = DELIM;
		array_word[i].references = constants::SUCCESS;
	}
	//array_word = new word[constants::MAX_WORDS];
}

//how many unique words are in array
int getArraySize() {
	int i;
	for (i = 0; array_word[i].references != 0; i++)
	return i;
}

//get data at a particular location
std::string getArrayWordAt(int i) {
	//return file_contents.find()
	return "poo";
}

int getArrayWord_NumbOccur_At(int i) {
	return 0;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream) {
	if(myfstream.is_open()) {
		string line;
		while(!myfstream.eof()) {
			getline(myfstream,line);
			processLine(line);
			file_contents += line;
		}
	  closeFile(myfstream);
	}
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString) {
	char token[myString.size() + 1];
	strcpy(token, myString.c_str());
	char * temp;
	temp = strtok(token, DELIM.c_str());
	string temp_string = token;
	processToken(temp_string);
	free(temp);
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {
	int i;
	cout << "Processing token..." << token << "...";
	for (i = 0; array_word[i].word != DELIM; i++) {
		if (array_word[i].word.compare(token) == constants::SUCCESS) {
			array_word[i].references++;
			return;
		}
	}
	cout << "Making: " << token << "...";
	array_word[i] = {token, 1};
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode) {
				myfile.open(myFileName.c_str(), mode);
				return true;
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
	return 0;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {

}
