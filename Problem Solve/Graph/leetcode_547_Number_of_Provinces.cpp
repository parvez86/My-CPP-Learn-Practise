#include <bits/stdc++.h>

using namespace std;

class Solution {
    void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
        //bfs
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i< graph[node].size(); i++){
                if(node==i) continue;
                if(graph[node][i]==1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
        //dfs
        stack<int> st;
        st.push(start);
        visited[start] = true;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(int i=0; i< graph[node].size(); i++){
                if(node==i) continue;
                if(graph[node][i]==1 && !visited[i]) {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size(), cnt=0;
        vector<bool> visited(len, false);
        for(int i=0; i<len; i++){
            if(!visited[i]){
                //bfs(i, isConnected, visited);
                dfs(i, isConnected, visited);
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> graph{
        {1, 1, 1}, {1, 1, 1}, {1, 1, 1}
    };
    cout<< obj.findCircleNum(graph)<< endl;
    return 0;
}
