#include <bits/stdc++.h>

using namespace std;


class Solution {
    vector<int> get_top_sort(vector<vector<int>> graph)
    {
        unsigned int n = graph.size();
        vector<unsigned int> out_degree(n, 0);
        // vector<bool> visited(n, false);
        vector<vector<unsigned int>> adj_list(n, vector<unsigned int>());
        queue<unsigned int> q;
        vector<int> result={};

        for(unsigned int i=0; i<n;i++){
            for(unsigned int node:graph[i]){
                adj_list[node].push_back(i);
                out_degree[i]++;
            }
            // add terminal nodes
            if(out_degree[i]==0) {q.push(i);}
        }

        // add non-terminal safe nodes
        while(!q.empty()){
            unsigned int node = q.front();
            q.pop();
            for(unsigned int neiv:adj_list[node]){
                if(--out_degree[neiv]==0){
                    q.push(neiv);
                }
            }
        }

        for(unsigned int i=0; i<n; i++) if(out_degree[i]==0) result.push_back(i);
        return result;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node){
        if(color[node]>0) return color[node] == 2;
        color[node] = 1;
        for(int neiv:graph[node]){
            if(color[neiv]==2) continue;
            if(color[neiv]==1 || !dfs(graph, color, neiv)) return false;
        }
        color[node] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return get_top_sort(graph);
    }
    vector<int> eventualSafeNodes2(vector<vector<int>>& graph) {
        vector<int> result={};
        vector<int> color(graph.size(), 0);
        for(int i=0; i<graph.size();i++){
            if(dfs(graph, color, i)) result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> graph = {
        // {1,2},{2,3},{5},{0},{5},{},{}
       // {1,2},{2,3,5,6},{5},{0},{5,6},{6},{}
         {}, {0, 2, 3, 4},{3}, {4},{}
    };

    vector<int> res = obj.eventualSafeNodes2(graph);
    cout<< "Safe nodes: ";
    for(int node:res) cout<< node<< " ";
    cout<< endl;
    return 0;
}
