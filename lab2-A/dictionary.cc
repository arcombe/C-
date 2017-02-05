#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream input("words.txt");
	string line;
	string word;
	vector<string> v;

	if(input.is_open()){
		while (getline(input, line)){
			v = split(line);
			word = v[0];
			set.insert(word);

			v.erase(v.begin(), v.begin() + 1);

			words[word.length()].push_back(Word(word,v));
		}
	}

}

std::vector<string> Dictionary::split(const string& word) const{
	
	vector<string> v;
	int prev = 0;

	for (decltype(word.size()) i = 0; i != word.size(); ++i){
		if (word[i] == ' '){
			v.push_back(word.substr(prev, i - prev));
			prev = i + 1;
		}
	}

	v.push_back(word.substr(prev, word.size()));

	return v;
}


bool Dictionary::contains(const string& word) const {
	return set.count(word);
}

vector<string> Dictionary::add_trigram_suggestions(const string& word) const {
	vector<string> v;
	vector<string> trio = getTrio(word);

	for (int i = 0; i != 3; ++i){
		for (Word w : words[word.length() - 1 + i]){
			
			if (w.get_matches(trio) > (word.length() - 2) / 2){
				v.push_back(w.get_word());
			}
		}
	}
	

	return v;
}

vector<pair<int, string>> Dictionary::rank_suggestions(const string& word, const vector<string> sugg) const{

	std::vector<pair<int, string>> v;

	for (string s : sugg){
		v.push_back(make_pair(edit_distance(word, s), s));
	}
	

	return v;
}

unsigned int Dictionary::edit_distance(const std::string& s1, const std::string& s2) const {
	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      // note that std::min({arg1, arg2, arg3}) works only in C++11,
                      // for C++98 use std::min(std::min(arg1, arg2), arg3)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

vector<string> Dictionary::trim_suggestions(const vector<pair<int, string>> sugg) const {
	vector<string> v;
	vector<pair<int, string>> suggestions = sugg;
	int count = 0;
	std::sort(suggestions.begin(), suggestions.end());
	for (pair<int, string> p : suggestions){
		if (count < 5){
			count ++;
			v.push_back(p.second);
		}
	}
	return v;
}


vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	std::vector<pair<int, string>> ranked_suggestions;

	suggestions = add_trigram_suggestions(word);
	ranked_suggestions = rank_suggestions(word, suggestions);
	suggestions = trim_suggestions(ranked_suggestions);

	return suggestions;
}

std::vector<string> Dictionary::getTrio(string word) const{
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	vector<string> v;
	string tri;

	if (word.size() < 3){
		return v;
	}

	for (decltype(word.size()) i = 0; i != word.size() - 2; ++i) {
		
		tri = word.substr(i, 3);
		v.push_back(tri);
	}

	sort( v.begin(), v.end());


	return v;
}

