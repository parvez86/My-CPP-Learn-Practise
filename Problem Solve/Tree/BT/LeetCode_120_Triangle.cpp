class Solution {
    int solveTriangle(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& res){
        if(row==n-1) return triangle[row][col];
        if(res[row][col] == -1) {
            int bottom = triangle[row][col]+solveTriangle(row+1, col, n, triangle, res);
            int bottom_next= triangle[row][col]+solveTriangle(row+1, col+1, n, triangle, res);
            res[row][col] = (bottom<bottom_next)?bottom:bottom_next;
        }

        return res[row][col];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> res(n, vector<int>(n, -1));
        return solveTriangle(0, 0, n, triangle, res);
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n, 0);
        for(int i=n-1; i>=0; i--){
            vector<int> rows(n, 0);
            for(int j=i; j>=0; j--){
                if(j==n-1) rows[j] = triangle[i][j];
                else{
                    int bottom = triangle[i][j]+next[j];
                    int bottom_next = triangle[i][j]+next[j+1];
                    rows[j] = min(bottom, bottom_next);
                }
            }

            next = rows;
        }
        return next[0];
    }
};

