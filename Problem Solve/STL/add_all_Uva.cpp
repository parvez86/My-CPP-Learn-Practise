#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    while(cin>> t)
    {
        long s=0;
        if(t==0) break;
        priority_queue<int,vector<int>,greater<int> > Q;
        int val;
        while(t--) {cin>> val; Q.push(val);}
        while(Q.size()>1){
            val = Q.top();
            Q.pop();
            val += Q.top();
            Q.pop();
            s+=val;
            Q.push(val);
        }
        cout<< s<< endl;
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      