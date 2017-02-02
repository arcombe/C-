#include "iostream"
#include "fstream"
#include "string"
#include "algorithm"

using namespace std;
int main(int argc, char const *argv[]) {
        if(argc!=3) {
                cout << "Usage: wordspp infile outfile";
                exit(EXIT_FAILURE);
        }

        ifstream infile (argv[1]);
        ofstream outfile (argv[2]);

        if(!infile.is_open()) {
                cout <<"Couldn't open inputfile";
                exit(EXIT_FAILURE);
        }
        if(!outfile.is_open()) {
                cout <<"Couldn't open outputfile";
                exit(EXIT_FAILURE);
        }

        string line;

        while(getline(infile, line)) {
                transform(line.begin(), line.end(), line.begin(), ::tolower);
                size_t num_trigrams = line.length()/3+line.length()%3;
                outfile << line << " " << num_trigrams;
                for(size_t i = 0; i<num_trigrams; ++i) {
                  outfile << " " << line.substr(i, 3);
                }
                outfile << endl;
        }

        infile.close();
        outfile.close();
        return 0;
}
