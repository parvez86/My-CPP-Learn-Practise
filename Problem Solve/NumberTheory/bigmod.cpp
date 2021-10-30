#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int getBigMod(string s, int m)
{
    int res = 0;
    for(int i=0; i<s.size(); i++){
        res = (res*10+(int)(s[i]-'0'))%m;
    }
    return res;
}

int main()
{
    string s;
    int m;
    cin>> s>>m;
    cout<< getBigMod(s,m)<< endl;
    return 0;
}
