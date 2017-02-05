#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t){
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int count = 0;
	for(string trigram : trigrams){
		for(string other_trigram : t){
			if (trigram == other_trigram){
				count += 1;
				break;
			}
		}
	}
	return count;
}
