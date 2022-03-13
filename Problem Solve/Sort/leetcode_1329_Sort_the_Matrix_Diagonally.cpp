#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int m = mat.size(), n=mat[0].size();

        // top to bottom
        for(int k=0; k<m; k++){
            for(int i=k, j=0; i<m && j<n; i++, j++){
                pq.push(mat[i][j]);
            }
            for(int i=k, j=0; i<m && j<n; i++, j++){
                mat[i][j] = pq.top();
                pq.pop();
            }
        }
        // left to right
        for(int k=1; k<n; k++){
            for(int i=0, j=k; i<m && j<n; i++, j++){
                pq.push(mat[i][j]);
            }
            for(int i=0, j=k; i<m && j<n; i++, j++){
                mat[i][j] = pq.top();
                pq.pop();
            }
        }
        return mat;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat{
        //{3,3,1,1},{2,2,1,2},{1,1,1,2}
        {37,98,82,45,42}
    };
    mat = obj.diagonalSort(mat);

    for(auto row:mat){
        for(int it:row) cout<< it<< " ";
        cout<< endl;
    }
    return 0;
}
