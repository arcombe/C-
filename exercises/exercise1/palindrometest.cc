#include "palindrome.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
        vector<string> s = {"anna","hej","amanaplanacanalpanama"};

        for_each(s.begin(),s.end(),[](string c){
                cout << c << ": " << palindrome(c) << endl;
        });
}
