#include "coding.h"
#include "iostream"
#include "fstream"
#include "string"

using namespace std;


int main()
{
	string line;
	Coding code;
	ifstream myfile ("file.enc");
	ofstream newfile ("file.dec");

	if(myfile.is_open()){
		while(getline(myfile, line)){
			for (string::size_type i = 0; i != line.size(); ++i) {
				newfile << code.decode(line[i]);
			}
			newfile << endl;
		}
	}
	myfile.close();
	newfile.close();
	
	
	return 0;
}

