#include <bits/stdc++.h>
using namespace std;

int getLongestPalindrome(string txt)
{
    int len = txt.size(), res = 0;
    stack<int> st;

    for(int i=0; i<len; i++){
        if(txt[i] == '(')  {st.push(i);continue;}

        if(!st.empty()) st.pop();

        if(!st.empty()) res = max(res, i-st.top());
        else st.push(i);
    }
    return res;
}


int getLongestPalindrome2(string txt)
{

}
int main()
{
    string str = "()()((()()(())))";
    string str2 = "abbcbbaabcabc";
    cout<< getLongestPalindrome(str)<< endl;
    //cout<< getLongestPalindrome2(str2)<< endl;
    return 0;
}
