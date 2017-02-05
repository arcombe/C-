#include <vector> 
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "setup.h"

using namespace std;

Setup::Setup() {
	ifstream input("/usr/share/dict/words");
	ofstream newfile("words.txt");
	vector<string> v;
	string line;

	if (input.is_open())
	{
		while(getline(input, line)){
			v = getTrio(line);
			newfile << line << " " << v.size();
			for (string s : v){
				newfile << " " << s;	
			}
			newfile << endl;
		}
	}
}

std::vector<string> Setup::getTrio(string word){
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
