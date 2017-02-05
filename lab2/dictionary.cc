#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"

using namespace std;


Dictionary::Dictionary(const string& filename){
	ifstream input (filename);
	if(!input.is_open()) exit(EXIT_FAILURE);
	string line;
	while(getline(input, line)){
			string word = line.substr(0, line.find(" "));
			words_set.insert(word);
			words[line.length()].push_back(Word(line,))
	}
}

Dictionary::Dictionary() : Dictionary("words.txt") {}

bool Dictionary::contains(const string& word) const {
	return words_set.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
