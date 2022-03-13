#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        if(s.size()==1) return 0;
        set<char> l, r;
        int len = s.size();
        vector<int> left(len, 0),right(len, 0);
        for(int i=0; i<len;i++){
            l.insert(s[i]);
            left[i] = l.size();
            r.insert(s[len-1-i]);
            right[len-1-i] = r.size();
        }
        int cnt=0;
        for(int i=0; i<len-1; i++){
            if(left[i]==right[i+1]) cnt++;
        }
        return cnt;
    }
    int numSplits2(string s) {
        bitset<26> b;
        int len=s.size();
        vector<int> left;
        for(int i=0; i<len; i++) {b[s[i]-'a']=1;left.push_back(b.count());}
        b.reset();
        int cnt=0;
        for(int i=len-1; i>=0; i--){
            if(b.count()==left[i]) cnt++;
            b[s[i]-'a'] = 1;
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    string s = "a";
    cout<< obj.numSplits(s)<< endl;
    cout<< obj.numSplits2(s)<< endl;
    return 0;
}

