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

	input.close();

}

vector<string> Dictionary::split(const string& word) const{
	
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

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	vector<string> triogram = get_Triogram(word);

	for (int i = 0; i != 3; ++i){
		for (Word w : words[word.length() - 1 + i]){
			
			if (w.get_matches(triogram) > (word.length() - 2) / 2){
				suggestions.push_back(w.get_word());
			}
		}
	}
}

vector<pair<int, string>> Dictionary::rank_suggestions(const vector<string>& suggestions, const string& word) const{

	vector<pair<int, string>> suggestions_with_rank;

	for (string s : suggestions){
		suggestions_with_rank.push_back(make_pair(edit_distance(word, s), s));
	}
	
	return suggestions_with_rank;
}

unsigned int Dictionary::edit_distance(const std::string& s1, const std::string& s2) const {
	const std::size_t len1 = s1.size(), len2 = s2.size();
	vector<vector<unsigned int>> d(len1 + 1, vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

void Dictionary::trim_suggestions(vector<pair<int, string>>& ranked_suggestions, vector<string>& suggestions) const {
	// vector<string> trimmed;
	suggestions.clear();

	int count = 0;

	std::sort(ranked_suggestions.begin(), ranked_suggestions.end());
	for (pair<int, string> p : ranked_suggestions){
		if (count < 5){
			count ++;
			suggestions.push_back(p.second);
		}
	}

}


vector<string> Dictionary::get_suggestions(const string& word) const {
vector<string> suggestions;
vector<pair<int, string>> ranked_suggestions;

	add_trigram_suggestions(suggestions, word);
	ranked_suggestions = rank_suggestions(suggestions, word);
	trim_suggestions(ranked_suggestions, suggestions);

return suggestions;
}

vector<string> Dictionary::get_Triogram(string word) const{
	
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	vector<string> triograms;
	string triogram;

	if (word.size() < 3){
		return triograms;
	}

	for (decltype(word.size()) i = 0; i != word.size() - 2; ++i) {
		triogram = word.substr(i, 3);
		triograms.push_back(triogram);
	}

	sort( triograms.begin(), triograms.end());

	return triograms;
}

