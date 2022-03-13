#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<int> in_degree;
    vector<bool> visited;

    void init_graph(int n){
        graph.resize(n, vector<int> ());
        in_degree.resize(n, 0);
        visited.resize(n, false);
    }

    void bfs(int start_node){
        visited[start_node] = true;
        queue<int> q({start_node});

        // visit all the connected unvisited node
        // make them visited
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i< graph[node].size(); i++){
                int temp_node = graph[node][i];
                if(!visited[temp_node]){
                    visited[temp_node] = true;
                    q.push(temp_node);
                }
            }
        }
        return;
    }

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0);
        // there is a unique valid path
        // if in-degree of a node is zero
        // then the node must be add to the path
        // otherwise there might at least a single path that reach the node
        for(int i=0; i<edges.size(); i++){
            //in_degree[edges[i][0]]--;
            in_degree[edges[i][1]]++;
        }

        vector<int> result;
        int i=0;

        // store the node having no in-degree
        for(int i=0; i<n; i++) if(in_degree[i]==0) result.push_back(i);
        return result;
    }
    vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>>& edges) {
        init_graph(n);
        // add node to the graph
        // add in-degree of each node
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            in_degree[edges[i][1]]++;
        }

        // store the nodes having zero-in-degree
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in_degree[i] == 0) q.push(i);
        }

        // the number of visited nodes
        // store the nodes with top-order
        vector<int> result;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(!visited[node]){
                result.push_back(node);
                bfs(node);
                // remove the nodes from each connected nodes
                // decrease the in-degree of each connected nodes by 1
                for(int i=0; i<graph[node].size(); i++){
                    int temp_node = graph[node][i];
                    if(--in_degree[temp_node] == 0) q.push(temp_node);
                }
            }
        }
        return result;
    }

    void print_path(vector<int> path){
        cout<< "The paths are: [";
        for(int j=0; j<path.size(); j++) {
            cout<< path[j];
            if(j != path.size()-1) cout<< ",";
        }
        cout<< "]";
    }
};

int main()
{
    Solution obj;
    int n = 5;
    vector<vector<int>> edges{
        {0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}
        // {0,1},{0, 2}, {2,5}, {3, 4}, {4, 2}, {2,5}
        // {1, 3},{2, 0}, {2, 3}, {1, 0}, {4, 1}, {0, 3}
    };
    vector<int> path = obj.findSmallestSetOfVertices2(n, edges);
    obj.print_path(path);
    return 0;
}
