#include <iostream>
#include <fstream>
#include <string>
#include "word.h"
#include "setup.h"
#include "dictionary.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// string line;
	// ifstream input("/usr/share/dict/words");
	// ofstream newfile("words.txt");

	// if (input.is_open())
	// {
	// 	while(getline(input, line)){
	// 		newfile << line << endl;
	// 	}
	// }
	// string s = "ok";
	// cout << s.size() << endl;

	// vector<string> v;
	// Word w("okok", v);
	// cout << w.get_word() << endl;

	// Setup s;	

	// std::vector<string> v;
	// string s = "jag vill splitta denna";
	// int prev = 0;
	// for (decltype(s.size()) i = 0; i != s.size(); ++i){
	// 	if (s[i] == ' '){
	// 		v.push_back(s.substr(prev, i - prev));
	// 		prev = i + 1;
	// 	}
	// }
	// v.push_back(s.substr(prev, s.size()));
	
	// for (string q : v){
	// 	cout << q << endl;
	// 	cout << q.size() << endl;
	// }

	// Dictionary d;
	// std::vector<string> v;
	// v = d.get_suggestions("correct");

	string a = "abc";
	string b = "abd";
	cout << a.compare(b) << endl;


	return 0;					
}






