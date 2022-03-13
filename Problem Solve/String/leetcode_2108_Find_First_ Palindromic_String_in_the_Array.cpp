#include <bits/stdc++.h>
using namespace std;


bool isPalindromic(string word){
    int len = word.size();
    for(int i=0; i<len/2; i++) if(word[i]!=word[len-1-i]) return false;
    return true;
}

string firstPalindrome(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{return a.size()<b.size();});

    for(int i=0; i<words.size(); i++){
        if(isPalindromic(words[i])) return words[i];
    }
    return "";
}

int main()
{
    int k=2;
    vector<string> vec{"abc","car","ada","racecar","cool"};
    cout<< firstPalindrome(vec)<< endl;
    return 0;
}

