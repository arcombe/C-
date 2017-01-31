#include <iostream>
#include "coding.h"

using namespace std;

Coding::Coding() {
	
}

Coding::~Coding() {
	
}

/* For any character c, encode(c) is a character different from c */
unsigned char Coding::encode(unsigned char c){
	int a = (int)c + 5;
	return (char)a;
}

/* For any character c, decode(encode(c)) == c */
unsigned char Coding::decode(unsigned char c){
	int a = (int)c - 5;
	return (char)a;
}




	


