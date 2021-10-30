#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        if(len==1) return false;
        for(int i=0; i<len;i++) {
            if((s[i]==')' && st.empty()) || (s[i]=='}' && st.empty()) || (s[i]==']' && st.empty())) return false;
            if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')) {st.pop();continue;}
            st.push(s[i]);
        }
        if (st.empty()) return true;
        return false;
    }
};

int main()
{
    Solution ob;
    string s = "{{{()[{{}()(())}(){}{()}]}}}";
    (ob.isValid(s))?cout<< "Valid"<< endl:cout<< "Not valid"<< endl;
    return 0;
}
