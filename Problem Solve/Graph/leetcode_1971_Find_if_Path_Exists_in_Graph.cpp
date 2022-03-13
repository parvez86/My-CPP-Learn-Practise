
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;
    void init_graph(int n){
        graph.resize(n, vector<int>());
        visited.resize(n, false);
    }

    bool bfs(int start_node, int end_node){
        queue<int> q;
        q.push(start_node);
        visited[start_node] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<graph[node].size(); i++){
                if(!visited[graph[node][i]]){
                    int temp = graph[node][i];
                    if(temp == end_node) return true;
                    visited[temp] = true;
                    q.push(temp);
                }
            }
        }
        return false;
    }

    bool dfs(int start_node, int end_node){
        stack<int> st;
        st.push(start_node);
        visited[start_node] = true;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(int i=0; i<graph[node].size(); i++){
                if(!visited[graph[node][i]]){
                    int temp = graph[node][i];
                    if(temp == end_node) return true;
                    visited[temp] = true;
                    st.push(temp);
                }
            }
        }
        return false;
    }

    void dfs2(int start_node, int end_node, bool& isValid){
        visited[start_node] = true;
        for(int i=0; i<graph[start_node].size(); i++){
            if(!visited[graph[start_node][i]]){
                int temp = graph[start_node][i];
                if(temp == end_node) isValid = true;
                visited[temp] = true;
                dfs2(temp, end_node, isValid);
            }
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(n==1) return true;
        init_graph(n);
        for(int i = 0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        bool isValid = false;
        dfs2(start, end, isValid);
        return isValid;
    }
};

int main()
{
    Solution obj;
    int n = 3, start=0, end=2;
    vector<vector<int>> edges{{0,1},{1, 2}, {2,0}};
    cout<< obj.validPath(n, edges, start, end)<< endl;
    return 0;
}
