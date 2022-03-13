#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool isValid(string s){
        int lo=0, up=0;
        for(char ch:s){
            if(ch < 'a') up |= 1<<(ch-'A') ;
            else lo |= 1<< (ch-'a');
        }
        return (lo^up)==0;
    }

public:
    string longestNiceSubstring(string s) {
        string niceStr="";
        for(int i=0; i<s.size(); i++){
            for(int j=2; j<=s.size(); j++){
                string sub = s.substr(i, j);
                if(isValid(sub)){
                    if(niceStr.size()<sub.size()) niceStr = sub;
                }
            }
        }
        return niceStr;
    }

};

int main()
{
    Solution obj;
    string str = "YazaAay";
    cout<< obj.longestNiceSubstring(str)<< endl;
    return 0;
}
