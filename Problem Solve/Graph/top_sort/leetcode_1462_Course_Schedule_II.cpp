#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        vector<int> out_degree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto nodes:prerequisites){
            graph[nodes[1]].push_back(nodes[0]);
            out_degree[nodes[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) if(out_degree[i]==0) q.push(i);

        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);

            for(int neiv:graph[node]){
                out_degree[neiv]--;
                if(out_degree[neiv]==0) q.push(neiv);
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};


int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        // {1, 0}, {2, 0}, {3, 1}, {3, 2}
        {1, 0}
    };

    Solution obj;
    vector<int> res = obj.findOrder(numCourses, prerequisites);

    for(int it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
