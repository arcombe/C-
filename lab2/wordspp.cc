#include "iostream"
#include "fstream"
#include "string"
#include "algorithm"
#include "vector"

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
                transform(line.begin(), line.end(), line.begin(), ::tolower); // to lower case
                size_t num_trigrams = line.length()/3+line.length()%3;
                outfile << line << " " << num_trigrams; // write word and number of trigrams

                vector<string> trigrams;
                for(size_t i = 0; i<num_trigrams; ++i) {
                  string trigram = line.substr(i, 3); // the i-th trigram
                  bool inserted=false;
                  for(vector<string>::iterator it = trigrams.begin(); it<trigrams.end(); ++it){
                    // if the  new trigram is less than the trigram at pos i then it should be inserted at pos i
                    if(trigram.compare(*it)<=0){
                      trigrams.insert(it,trigram);
                      inserted=true;
                      break;
                    }
                  }
                  // if no trigrams was found that was less than the new trigram
                  // then it should be inserted last
                  if(!inserted) trigrams.push_back(trigram);
                }
                //write the trigrams to outfile
                for(string& trigram : trigrams){
                  outfile << " " << trigram;
                }
                outfile << endl;
        }

        infile.close();
        outfile.close();
        return 0;
}
