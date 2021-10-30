#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int flag[26], flag2[52];


void count_char(string text)
{
    int len = text.size();
    for(int i=0; i<len; i++){
        if(isalpha(text[i])){
            if(islower(text[i])){
                flag[text[i]-'a']++;
                flag2[text[i]-'a']++;
                continue;
            }
            flag[text[i]-'A']++;
            flag2[(text[i]-'A')+26]++;
        }
    }
    return;
}

void display_count_with_ignore_case_diff()
{
    cout<< "Ignoring case difference: "<< endl;
    for(int i=0; i<26; i++){
        cout<< (char)(i+'a')<< ": "<< flag[i]<< endl;
    }
}

void display_count_with_case_diff()
{
    for(int i=0; i<26; i++){
        cout<< (char)(i+'a')<<": "<< flag2[i]<< "\t"<< (char)(i+'A')<< ": "<< flag2[i+26]<< endl;
    }
}
// using stl
void display_count_char2_with_ignore_case_diff(string text)
{
    int len = text.size();
    map<char, int> mp;
    for(int i=0; i<len; i++){
        if(isalpha(text[i])){
            if(isupper(text[i])) {mp[text[i]-'A'+'a']++; continue;}
            mp[text[i]]++;
        }
    }
    cout<< "The count of character: "<< endl;
    for(auto it= mp.begin(); it!=mp.end(); it++){
        cout<< it->first<< ": "<< it->second<< "\t";
        it++;
        if(it!=mp.end()){
            cout<< it->first<< ": "<< it->second<< endl;
        }
    }
}
int main()
{
    string text = "Infuse your life with action. Don't wait for it to happen."
    " Make it happen. Make your own future. Make your own hope. Make your own love."
    " And whatever your beliefs, honor your creator, not by passively waiting for"
    " grace to come down from upon high, but by doing what you can to make grace happen..."
    " yourself, right now, right down here on Earth.";

    count_char(text);
    display_count_with_case_diff();
    display_count_with_ignore_case_diff();
    display_count_char2_with_ignore_case_diff(text);
    return 0;
}
