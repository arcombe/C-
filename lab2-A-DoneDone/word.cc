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
	int diff;
	for(string trigram : trigrams){
		for(string other_trigram : t){
			diff = trigram.compare(other_trigram);
			if (diff <= 0){
				if (diff == 0) count += 1;
				break;
			}
		}
	}
	return count;
}
