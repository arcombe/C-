#include <iostream>

using namespace std;

// Pointers
int main (){
	int x = 27;
	int* y = &x;
	int& z = x;
	
	cout << *y << endl;
	cout << z << endl;

}
