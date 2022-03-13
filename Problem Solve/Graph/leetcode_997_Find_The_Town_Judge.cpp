#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> flag(n+1, 0);
        for(int i=0; i<trust.size(); i++){
            flag[trust[i][0]]--;
            flag[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++) if(flag[i]==n-1) return i;
        return -1;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    vector<vector<int>> vec{{1,3},{1, 4}, {2,3}, {2, 4}, {4, 3}};
    cout<< obj.findJudge(n, vec)<< endl;
    return 0;
}
