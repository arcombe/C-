#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
  int size = stoi(argv[1]);
  string out=argv[2];
  string s (size, 'P');
  s[0]=s[1]='C';

  int p=2;
  while(p<size){
    int i=2*p;
    while(i<size){
      s[i]='C';
      i=i+p;
    }
    p++;
    while(s[p]=='C'){
      p++;
    }
  }
  if(out=="all"){
    for(decltype(s.length()) i=0; i<s.length();++i){
      if(s[i]=='P') cout << i << " ";
    }
  }
  else if(out=="largest"){
    for(auto i = s.length()-1; i>=0; --i){
      if(s[i]=='P'){
        cout << i;
        break;
      }
    }
  }
}
