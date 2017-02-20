#include <iostream>
#include <string>
#include <fstream>
#include "for4.h"

using namespace std;

for4::for4(){

	string v;
}

string for4::strip(const string& str){
	string result;
	for (char s : str){
		result += s;
		result += " ";
	}
	return result;
}

int main(int argc, char const *argv[])
{
	for4 f;

	// convert from string and back.
	string s1 = "123.45";
	double nbr = stod(s1);
	string s2 = to_string(nbr + 1);
	//cout << s2 << endl;

	string s3 = "Alexander";
	cout << f.strip(s3) << endl;

	return 0;
}

