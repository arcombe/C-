#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t):  word(w), trigrams(t){}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int count = 0;
	int i = 0, j = 0, diff;

	while(i != static_cast<int>(trigrams.size()) && j != static_cast<int>(t.size())){
		diff = trigrams[i].compare(t[j]);
		if (diff < 0) i++;
		else if (diff > 0) j++;
		else {
			count += 1;
			i++;
		}
	}

	return count;
}

// unsigned int Word::get_matches(const vector<string>& t) const {
// 	unsigned int count = 0;
// 	int diff;
// 	for(string trigram : trigrams){
// 		for(string other_trigram : t){
// 			diff = trigram.compare(other_trigram);
// 			if (diff <= 0){
// 				if (diff == 0) count += 1;
// 				break;
// 			}
// 		}
// 	}
// 	return count;
// }
