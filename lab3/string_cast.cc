#include "date.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
T string_cast(string s){
  istringstream iss(s);
  T t;
  iss >> t;
  return t;
}

int main(){
  try {
    int i = string_cast<int>("123");
    double d = string_cast<double>("12.34");
    Date date = string_cast<Date>("2015-01-10");

    cout << "int: " << i << endl;
    cout << "double: " << d << endl;
    cout << "Date: " << date << endl;

  } catch (std::invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
