#include <iostream> // input-output lib 
#include <fstream>
#include <string>
using namespace std;

// int main() {
// 	int sum = 0;
// 	int value;
// 	while (std::cin >> value) {
// 		sum += value;
// 	}
// 	std::cout << "The sum is: " << sum << std::endl;
// }

int main (){
	ifstream input("text.txt");
	string line;

	if (input.is_open()){
		getline(input, line);
		cout <<  line << endl;
	}

	input.close();
}

