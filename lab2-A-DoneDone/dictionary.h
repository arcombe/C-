#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:

	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	std::vector<std::string> split(const std::string& word) const;

private:
	
	void trim_suggestions(std::vector<std::pair<int, std::string>>& ranked_suggestions, std::vector<std::string>& suggestions) const;
	unsigned int edit_distance(const std::string& s1, const std::string& s2) const;
	std::vector<std::pair<int, std::string>> rank_suggestions( const std::vector<std::string>& suggestions, const std::string& word) const;
	void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	std::vector<std::string> get_Triogram( std::string word) const;

	std::unordered_set<std::string> set;
	std::vector<Word> words[25];

};

#endif
