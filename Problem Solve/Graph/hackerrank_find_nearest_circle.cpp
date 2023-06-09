#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

int bfs(vector<vector<int>> graph, vector<int> vis, vector<int> dist, vector<long int> ids, long int color, int start){
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    dist[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<graph[node].size(); i++){
            if(!vis[graph[node][i]]){
                vis[graph[node][i]] = 1;
                dist[graph[node][i]] = dist[node]+1;
                if(ids[graph[node][i]]==color) return dist[graph[node][i]];
                q.push(graph[node][i]);

            }
        }
    }
    return INT_MAX;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    vector<vector<int>> graph(graph_nodes, vector<int>());
    vector<int>  vis(graph_nodes, 0);
    for(int i=0; i<graph_from.size(); i++){
        graph[graph_from[i]-1].push_back(graph_to[i]-1);
        graph[graph_to[i]-1].push_back(graph_from[i]-1);
    }
    int min_path=INT_MAX;
    for(int i=1; i<ids.size(); i++){
        if(ids[i]==val){
            vis.resize(graph_nodes, 0);
            int path = bfs(graph, vis, vector<int>(graph_nodes, 0), ids, ids[i], i);
            if(min_path>path) min_path= path;
        }
    }
    return min_path==INT_MAX?-1:min_path;
}
