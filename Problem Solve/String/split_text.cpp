#include <bits/stdc++.h>
//#include <boost/algorithm/string.hpp>

using namespace std;

vector<string> tokenize(string str, regex re)
{
    sregex_token_iterator it{str.begin(), str.end(), re, -1};
    vector<string> tokenized {it, {}};

    tokenized.erase(
        remove_if(tokenized.begin(), tokenized.end(),
                  [](string const& s){return s.size()==0;}),
        tokenized.end()
    );
    return tokenized;
}

void split_text1(string txt)
{
    cout<< txt<< endl;
    string word;

    string delim = " |,';-";
    istringstream ss(txt);
    while(ss.good()){
        getline(ss, word, ' ');
        cout<< word<< endl;
    }
    cout<< endl;
    return;
}

/*void split_text2(string txt)
{
    cout<< txt<< endl;
    string word;
    string delim = " |,';-";
    vector<string> words;
    split(words, txt, is_any_of(delim));
    for(string st:words) cout<< st<< endl;
    cout<< endl;
    return;
}*/

void split_text2(string txt)
{
    cout<< "Using regex: ";
    //regex re ("[\\|,':;.-]");
    regex re ("[^a-zA-Z\d]");
    sregex_token_iterator first{txt.begin(), txt.end(), re, -1}, last;
    vector<string> words{first, last};
    for(string it:words) cout<< it<< " ";
    cout<< endl;
}

void split_text3(string txt)
{
    regex re("[^a-zA-Z0-9]");
    vector<string> words = tokenize(txt, re);
    cout<< "Using regex2: ";
    for(string it:words) cout<< it<< " ";
    cout<< endl;
    return;
}

int main()
{
    string txt = "You've gotta dance like there's nobody watching,\n"
    "Love like you'll never be hurt,\n"
    "Sing like there's nobody listening,\n:"
    "And live like it's heaven on earth. -William W. Purkey";

    // split_text1(txt);
    split_text2(txt);
    split_text3(txt);
    return 0;
}


/*

const std::string delims(";,:. \n\t");
inline bool isDelim(char c) {
    for (int i = 0; i < delims.size(); ++i)
        if (delims[i] == c)
            return true;
    return false;
}

std::stringstream stringStream(inputString);
std::string word; char c;

while (stringStream) {
    word.clear();

    // Read word
    while (!isDelim((c = stringStream.get())))
        word.push_back(c);
    if (c != EOF)
        stringStream.unget();

    wordVector.push_back(word);

    // Read delims
    while (isDelim((c = stringStream.get())));
    if (c != EOF)
        stringStream.unget();
}

*/
