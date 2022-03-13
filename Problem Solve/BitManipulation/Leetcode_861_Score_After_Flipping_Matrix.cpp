#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rw = grid.size(), col=grid[0].size();
        int mx_score=0;
        // generate score
        // if grid[row][0] count with row shift
        // if #of 1 < #of 0 count with col shift
        for(int j=0, k=(1<< col-1); j<col; j++, k>>=1){
            int cnt=0;
            for(int i=0; i<rw; i++) if(grid[i][j]==grid[i][0])cnt++;
            mx_score+= k*max(cnt, rw-cnt);

        }
        return mx_score;
    }

    int matrixScore2(vector<vector<int>>& grid) {
        int rw = grid.size(), col=grid[0].size();
        int mx_score=0;
        // row shift
        for(int i=0; i<rw; i++){
            if(grid[i][0]==0){
                for(int j=0; j<col; j++) grid[i][j]^=1;
            }
        }

        // col shift
        // generate score
        for(int j=0, k=(1<< col-1); j<col; j++, k>>=1){
            int cnt=0;
            for(int i=0; i<rw; i++) if(grid[i][j])cnt++;
            mx_score+= k*max(cnt, rw-cnt);

        }
        return mx_score;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid{
        {0,0,1,1},{1,0,1,0},{1,1,0,0}
    };
    cout<< obj.matrixScore(grid)<< endl;
    return 0;
}
