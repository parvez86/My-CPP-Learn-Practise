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
    stack<char> st_c;
    stack<int> st_i;
    
    int len = txt.size(), res = 0;

    for(int i=0; i<len; i++){
        if(st_c.empty() || st_c.top() != txt[i]){
            st_c.push(txt[i]);
            st_i.push(i);
            continue;
        }
        
        st_c.pop(); st_i.pop();

        if(!st_i.empty()) res = max(res, i-st_i.top());
        else res = max(res, i+1);
    }
    return res;
    
}

int main()
{
    string str = "()()((()()(())))";
    string str2 = "abbcbbaabcabc";
    cout<< getLongestPalindrome(str)<< endl;
    //cout<< getLongestPalindrome2(str2)<< endl;
    return 0;
}
