#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class ReplaceRegex {
public:
ReplaceRegex(string re, string replace) : re(re), replace(replace){
}
string r_replace(const string& s) const {
        return regex_replace(s, regex(re),replace);
}

private:
string re;
string replace;
};

int main(int argc, char const *argv[] ){
        if (argc!=3) {
                cout << "Usage: tag_remover infile outfile";
                exit(1);
        }
        ifstream ifs (argv[1]);
        ofstream ofs (argv[2]);

        if(!ifs.is_open()) {
                cout << "Could not open " << argv[1];
        }
        if(!ofs.is_open()) {
                cout << "Could not open " << argv[2];
        }
        ;
        regex open_tag("<[^>]*$");
        regex end_tag("^.*?>");

        vector<ReplaceRegex> regexes = {
                ReplaceRegex("<.*?>",""),
                ReplaceRegex("&lt;","<"),
                ReplaceRegex("&gt;",">"),
                ReplaceRegex("&nbsp;"," "),
                ReplaceRegex("&amp;","&")
        };
        string line;
        bool is_tag_open=false;

        while(getline(ifs, line)) {
                if(is_tag_open) {
                        if(!regex_search(line,end_tag)) {
                                ofs << endl;
                                continue;
                        }
                        line = regex_replace(line, end_tag, "");
                }
                if((is_tag_open=regex_search(line,open_tag))) {
                        line = regex_replace(line,open_tag,"");
                }
                for(ReplaceRegex r : regexes) {
                        line=r.r_replace(line);
                }
                ofs << line << endl;
        }
        cout << "Done";

        ifs.close();
        ofs.close();
}
