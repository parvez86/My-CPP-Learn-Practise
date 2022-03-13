
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky_num;
        int m = matrix.size();
        int n = matrix[0].size();
        cout<< n<< endl;
        for(int i=0; i<m; i++){
            // row min
            int min_col = 0, min_val = matrix[i][0];
            for(int j=1; j<n; j++){
                if(min_val > matrix[i][j]){min_col = j; min_val=matrix[i][j];}
            }

            // col max;
            int max_row = 0, max_val = matrix[0][min_col];
            for(int j=1; j<m; j++){
                if(max_val < matrix[j][min_col]){max_row = j; max_val=matrix[j][min_col];}
            }
            if(min_val == max_val && min_val==matrix[max_row][min_col]) lucky_num.push_back(min_val);
            cout<< min_col<< "\t"<< max_row<< "\t"<< min_val<< "\t"<< max_val<< "\t"<< matrix[max_row][min_col]<< endl;
        }
        return lucky_num;
    }
};

void print(vector<int> arr)
{
    cout<< "The items are: ";
    for(int i=0; i<arr.size(); i++) cout<< arr[i]<< " ";
    cout<< endl;
}

int main()
{
    Solution obj;
    vector<vector<int>> vec = {
        //{3,7,8}, {9,11,13}, {15,16,17}
        // {7,8}, {1,2}
        {1,10,4,2}, {9,3,8,7}, {15,16,17,12}
    };

    vector<int> res = obj.luckyNumbers(vec);
    print(res);
    return 0;
}

