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
#include "array_functions.h"
#include "utilities.h"
CHAR_TO_SEARCH_FOR = "";
MAX_WORDS = 2100;
SUCCESS = 0;
using namespace std;

struct word {
	string word = CHAR_TO_SEARCH_FOR;
	int references = SUCCESS;
};

word array_struct[MAX_WORDS];

string file_contents;

void clearArray() {
	delete [] array_struct;
	array_struct = new word array_struct[MAX_WORDS];
}

//how many unique words are in array
int getArraySize() {
	int i;
	for (i = 0; array_struct[i] != null; i++)
	return i;
}

//get data at a particular location
std::string getArrayWordAt(int i) {
	//return file_contents.find()
}

int getArrayWord_NumbOccur_At(int i) {

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
	string token;
	while (getline(myString,token,CHAR_TO_SEARCH_FOR)) {
	   processToken(token);
	}
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {
	int i;
	for (i = 0; array_struct[i].word != CHAR_TO_SEARCH_FOR; i++) {
		if (array_struct[i].word.strcmp(token) == SUCCESS) {
			array_struct[i].references++;
			return;
		}
	}
	array_struct[i] = new word(token, 1);
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName) {
				myfile.open(myFileName.c_str(), std::ios_base::in);
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

}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {

}
