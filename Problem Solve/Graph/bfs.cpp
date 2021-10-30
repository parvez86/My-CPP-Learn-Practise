#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void insert_edge(vector<vector<int>>& graph, pair<int, int> edge)
{
    graph[edge.first].push_back(edge.second);

    // bi-directional
    graph[edge.second].push_back(edge.first);
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    while(!q.empty()){
        int node = q.front();
        cout<< node<< " ";
        q.pop();
        int len = graph[node].size();
        for(int i=0; i<len; i++){
            if(!visited[graph[node][i]]){
                q.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }
}

void get_bfs(vector<vector<int>>& graph, int start_node)
{
    int len = graph.size();
    vector<bool> visited(graph.size(), false);
    cout<< "The visited nodes are (using bfs): "<< endl;
    bfs(graph, visited, start_node);
    for(int i=0; i<len; i++){
        if(i==start_node) continue;
        if(!visited[i]){
            bfs(graph, visited, i);
        }
    }
    cout<< endl;
}

int main()
{
    // pair<int, int> edge;
    int a[] = {2, 3, 1, 5, 0, 4, 3, 6};
    int len = sizeof(a)/sizeof(a[0]);
    set<int> st(a, a+len);
    vector<vector<int>> graph(st.size(), vector<int>());
    cout<< "The edges are: "<< endl;
    for(int i=0; i<len-1; i++){
        cout<< a[i]<< " "<< a[i+1]<< endl;
        insert_edge(graph, make_pair(a[i], a[i+1]));
    }
    int start_node = 2;
    get_bfs(graph, start_node);
    return 0;
}
