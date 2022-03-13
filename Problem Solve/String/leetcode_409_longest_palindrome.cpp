#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        int len = s.size();
        for(int i=0; i<len; i++){
            mp[s[i]]++;
        }
        int res=0;
        bool isOdd = false;
        for(const auto it:mp){
            if(!isOdd && it.second%2==1) isOdd = true;
            res+= (int)(it.second/2)*2;
        }
        if(isOdd) res+=1;
        return res;
    }
};

int main()
{
    Solution obj;
    string text = "bbcba";
    cout << obj.longestPalindrome(text)<< endl;
    return 0;
}
