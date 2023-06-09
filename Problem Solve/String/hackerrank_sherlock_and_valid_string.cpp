#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
int flag[26];
string isValid(string a) {
    int len = a.size();
    int count_1 = 0;
    if(len==1) return "YES";
    for(int i=0; i<len; i++) {flag[a[i]-'a']++;}

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<26; i++) {
        if(flag[i]>0) {
            if(flag[i] == 1) count_1++;
            pq.push(flag[i]);
        }
    }
    int total_dist = (count_1==1)?1:0;
    if(pq.top()==1) {pq.pop();}
    int min_cnt = pq.top();
    while(!pq.empty()){
        total_dist += pq.top()-min_cnt;
        pq.pop();
    }
    return (total_dist<=1)? "YES":"NO";
}
