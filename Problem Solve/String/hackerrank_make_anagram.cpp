#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int flag[26];
int makeAnagram(string a, string b) {

    int len = a.size();
    for(int i=0; i<len; i++) flag[a[i]-'a']++;

    len = b.size();
    for(int i=0; i<len; i++) flag[b[i]-'a']--;

    int sum = 0;
    for(int i=0; i<26; i++) {
        sum += abs(flag[i]);
    }

    return sum;
}
