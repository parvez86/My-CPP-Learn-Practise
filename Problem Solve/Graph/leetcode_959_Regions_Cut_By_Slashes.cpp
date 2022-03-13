#include <bits/stdc++.h>

using namespace std;


class Solution {
    vector<int> parents;
    vector<int> ranks;

    int cnt;

    void init_pr(int n){
        parents.resize(n, -1);
        ranks.resize(n, 1);
        cnt=1;
        for(int i=0; i<n; i++) parents[i] = i;
    }

    int find_parent(int node){
        if(node == parents[node]) return node;
        return parents[node] = find_parent(parents[node]);
    }

    void unionn(int u, int v){

        u = find_parent(u);
        v = find_parent(v);

        if(u != v){
            if(ranks[u] < ranks[v]) parents[u] = v;
            else{
                parents[v] = u;
                if(ranks[u] == ranks[v]) ranks[u]++;
            }
        }else{
            cnt++;
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dts = n+1;
        init_pr(dts*dts+1);

        for(int i=0; i<dts; i++){
            for(int j=0; j<dts; j++){
                if(i==0 || j==0 || i==dts-1 || j==dts-1) {
                    int cell = i*dts+j;
                    if(cell != 0) unionn(0, cell);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]== '/'){
                    int cell1 = i*dts+(j+1);
                    int cell2 = (i+1)*dts+j;
                    unionn(cell1, cell2);
                }
            else if(grid[i][j] == '\\'){
                int cell1 = i*dts+j;
                int cell2 = (i+1)*dts+(j+1);
                unionn(cell1, cell2);
                }
            }
        }

        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<string> vec{
         {" /"},{"/ "}
        //{"/\\"},{"\\/"}
    };
    cout<< obj.regionsBySlashes(vec)<< endl;
    return 0;
}
