#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	Dictionary(const std::string& filename);
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	std::unordered_set<std::string> words_set;
	std::vector<Word> words[25];
	std::string find_trigrams(const string& s, size_t pos);
};

#endif
