#include <iostream>

using namespace std;

int flag[26];


bool check_anagram(string txt1, string txt2)
{
    if(txt1.size() != txt2.size()) return false;
    int len = txt1.size();
    for(int i=0; i<len; i++) {flag[txt1[i]-'a']++; flag[txt2[i]-'a']--;}
    for(int i=0; i<26; i++) {
        if(flag[i] != 0) return false;
    }
    return true;
}
int main()
{
    string txt1, txt2;
    cin>> txt1;
    cin>> txt2;

    (check_anagram(txt1, txt2))? cout<< "The two strings are anagram of each other"<<endl:
        cout<< "The two strings are not anagram of each other"<< endl;
    return 0;
}
