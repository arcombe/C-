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
	vector<string> triograms;
	string line;

	if (input.is_open())
	{
		while(getline(input, line)){
			// transform(line.begin(), line.end(), line.begin(), ::tolower);
			triograms = get_Triograms(line);
			newfile << line << " " << triograms.size();
			for (string triogram : triograms){
				newfile << " " << triogram;	
			}
			newfile << endl;
		}
	}

	newfile.close();
	input.close();
}

vector<string> Setup::get_Triograms(string word){
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

int main(int argc, char const *argv[])
{
	Setup s;
	return 0;
}




