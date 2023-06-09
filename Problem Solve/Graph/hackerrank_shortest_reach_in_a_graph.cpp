#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    vector<vector<int>>graph;
    vector<int> vis;
    vector<int> dist;
    public:
        Graph(int n) {
            graph.resize(n, vector<int>());
            vis.resize(n, 0);
            dist.resize(n, -1);
        }

        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        void bfs(int start)
        {
            queue<int> q;
            q.push(start);
            vis[start] = 1;
            dist[start] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(unsigned int i=0; i<graph[node].size(); i++){
                    if(!vis[graph[node][i]]){
                        vis[graph[node][i]] = 1;
                        dist[graph[node][i]] = dist[node]+6;
                        q.push(graph[node][i]);
                    }
                }
            }
        }
        vector<int> shortest_reach(int start) {
            bfs(start);
            dist[start] = -1;
            return dist;
        }
};
