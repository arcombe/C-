// #include <string>
// #include <fstream>
// #include <regex>
// #include <iostream>
// #include <vector>
// #include <utility>
// using namespace std;

// class prime_finder {
// public:

// prime_finder(int m) : m(m){
//         s = string(m + 1, 'P');
//         s.replace(0,1,"C");
//         s.replace(1,1,"C");
//         primes.push_back(2); 
// }

// std::vector<int> get_primes (){
//         find_primes();
//         return primes;
// }

// int get_last_prime(){
//         current_prime = 2;
//         find_last_primes();
//         return current_prime;
// }

// private:

// int m;
// string s;
// std::vector<int> primes;

// void find_primes (){
//         current_prime = primes[primes.size() - 1];
//         string::size_type found;
//         int multiplier = 2;
//         string tmp;

//         while (current_prime * multiplier <= m) {
//                 s.replace(current_prime * multiplier, 1, "C");
//                 multiplier++;
//         }
//         tmp = s.substr(current_prime + 1, m - current_prime);

//         found = tmp.find("P");

//         if (found != string::npos){
//                 primes.push_back(found + current_prime + 1);
//                 find_primes();
//         }
// }

// int current_prime;

// void find_last_primes () {

//         string::size_type found;
//         int multiplier = 2;
//         string tmp;

//         while (current_prime * multiplier <= m) {
//                 s.replace(current_prime * multiplier, 1, "C");
//                 multiplier++;
//         }

//         tmp = s.substr(current_prime + 1, m - current_prime);

//         found = tmp.find("P");

//         if (found != string::npos){ 
//                 current_prime = found + current_prime + 1;
//                 find_last_primes();
//         } 
// }

// };

// int main(int argc, char const *argv[] ){
        
//        prime_finder pf1 = prime_finder(100); 

//        for (int x : pf1.get_primes()){
//                 cout << x << " " ;
//        }
//        cout << endl;

//        prime_finder pf2 = prime_finder(80000);
//        cout << pf2.get_last_prime() << endl;


     
// }

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
