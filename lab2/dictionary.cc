#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;


Dictionary::Dictionary(const string& filename){
	ifstream input (filename);
	if(!input.is_open()) exit(EXIT_FAILURE);
	string line;
	while(getline(input, line)){
			string word = line.substr(0, line.find(" "));
			words.insert(word);
	}
}

Dictionary::Dictionary() : Dictionary("words.txt") {}

bool Dictionary::contains(const string& word) const {
	return words.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
