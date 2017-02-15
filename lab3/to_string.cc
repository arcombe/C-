#include "date.h"
#include <string>
#include <sstream>


template <typename T>
std::string toString(const T& t){
  std::ostringstream oss;
  oss << t;
  return oss.str();
}


int main(){
  double d = 1.234;
  Date today;
  std::string sd = toString(d);
  std::string st = toString(today);
  std::cout << "Double: " << sd << std::endl;
  std::cout << "Today: " << st << std::endl;
}
