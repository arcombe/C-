#ifndef SETUP_H // include guard, necessary to avoid
#define SETUP_H // inclusion more than once

#include <string>
#include <vector>


class Setup {
public:
	
	Setup(); 
	std::vector<std::string> get_Triograms(std::string word);
	int main(int argc, char const *argv[]);

private:



};

#endif
