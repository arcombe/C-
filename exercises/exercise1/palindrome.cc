#include "palindrome.h"
#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s){
  for(size_t i=0;i<s.length();i++){
    if(s[i]!=s[s.length()-1-i]) return false;
  }
  return true;
}
