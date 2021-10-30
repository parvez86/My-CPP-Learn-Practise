#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string txt, word;
    set<string> st;
    getline(cin, txt, static_cast<char>(EOF));
    int len = txt.size();
    for(int i=0; i<len; i++){
        // if not alphabet assign white space character
        if(!isalpha(txt[i])) {txt[i]=' ';continue;}
        // convert upper -> lower case
        if(isupper(txt[i])) txt[i]+=32;
    }
    istringstream ss(txt);
    // tokenize the sentence until EOF
    while(ss>>word){
        st.insert(word);
    }
    for(auto x:st) cout<< x<< endl;
    return 0;
}
