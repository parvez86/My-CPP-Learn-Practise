#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "Hi! How are you? ";
    string s1 = "Sp?";
    cout << s.length() << endl;
    cout << s.size() << endl;
    s.resize(20);
    cout << s<< endl;
    s.swap(s1);
    cout<< s1<< s << s.max_size() << endl;
    return 0;
}
