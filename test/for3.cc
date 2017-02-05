#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int main (){

	int a = 0; 
	auto b = a; // auto gör det till samma typ som är till höger 

	// vector<int> v;
	// auto c = v; // c blir in vector
	// decltype d = v; // decltype gör det till värdet som funktionen/expression ger.
	// 				// i detta fall blir d en inte.
	// d = 2;
	// cout << d << endl;

	// strings är som sb i java
	cout << "type your name: ";
	string name;
	cin >> name;
	cout << "Your name: " + name << endl;

	// loopa genom en string
	for (decltype(name.size()) i = 0; i != name.size(); i++){
		cout << name[i];
	}
	cout << endl;

	name = "Jonas";

	for (char c : name){
		cout << c;
	}
	cout << endl;

	// vector
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// iterera genom vector
	// cbegin() och cend() gör att man endast kan läsa.
	for(auto it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	for (int& i : v){
		cout << i << " ";
	}










} 
