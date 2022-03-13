#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> flag(51, false);
        int len = ranges.size();
        for(int i=0; i<len; i++){
            for(int j=ranges[i][0]; j<=ranges[i][1]; j++) flag[j] = true;
        }
        for(int i=left; i<=right; i++){
            if(!flag[i]) return false;
        }
        return true;
    }

    bool isCovered2(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> flag(right-left+1, false);
        int len = ranges.size();
        for(int i=0; i<len; i++){
            for(int j=ranges[i][0]; j<=ranges[i][1]; j++) if(j>=left && j<=right) flag[j-left] = true;
        }
        for(int i=0; i<flag.size(); i++){
            if(!flag[i]) return false;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> ranges={
        {1, 10},{10,21}
        // {1, 2},{3,4},{5,6}
        // {1, 50}
    };
    // int left = 1, right=50;
    // int left = 2, right=5;
    int left = 21, right=21;
    (obj.isCovered(ranges, left, right))? cout<< "True"<< endl:cout<< "False"<< endl;
    (obj.isCovered2(ranges, left, right))? cout<< "True"<< endl:cout<< "False"<< endl;
    return 0;
}
