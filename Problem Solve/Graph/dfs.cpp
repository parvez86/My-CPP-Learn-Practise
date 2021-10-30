#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

void insert_edge(vector<vector<int>>& graph, pair<int, int> edge)
{
    graph[edge.first].push_back(edge.second);

    // bi-directional
    graph[edge.second].push_back(edge.first);
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start_node)
{
    stack<int> st;
    st.push(start_node);
    visited[start_node] = true;
    while(!st.empty()){
        int node = st.top();
        cout<< node<< " ";
        st.pop();
        int len = graph[node].size();
        for(int i=0; i<len; i++){
            if(!visited[graph[node][i]]){
                st.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }
}

void dfs_with_rec(vector<vector<int>>& graph, vector<bool>& visited, int start_node)
{
    visited[start_node] = true;
    cout<< start_node<< endl;
    int len = graph[start_node].size();
    for(int i=0; i<len; i++){
        if(!visited[graph[start_node][i]]){
            dfs_with_rec(graph, visited, graph[start_node][i]);
        }
    }
}

void get_dfs(vector<vector<int>>& graph, int start_node)
{
    int len = graph.size();
    vector<bool> visited(graph.size(), false);
    cout<< "The visited nodes are (using dfs): "<< endl;
    dfs(graph, visited, start_node);
    for(int i=0; i<len; i++){
        if(i==start_node) continue;
        if(!visited[i]){
            dfs(graph, visited, i);
        }
    }
    cout<< endl;
}

void get_dfs_rec(vector<vector<int>>& graph, int start_node)
{
    int len = graph.size();
    vector<bool> visited(graph.size(), false);
    cout<< "The visited nodes are (using dfs): "<< endl;
    dfs(graph, visited, start_node);
    for(int i=0; i<len; i++){
        if(i==start_node) continue;
        if(!visited[i]){
            dfs_with_rec(graph, visited, i);
        }
    }
    cout<< endl;
}

int main()
{
    // pair<int, int> edge;
    int a[] = {2, 3, 1, 5, 0, 4, 3, 6, 7};
    int len = sizeof(a)/sizeof(a[0]);
    set<int> st(a, a+len);
    vector<vector<int>> graph(st.size(), vector<int>());
    cout<< "The edges are: "<< endl;
    for(int i=0; i<len-1; i++){
        cout<< a[i]<< " "<< a[i+1]<< endl;
        insert_edge(graph, make_pair(a[i], a[i+1]));
    }
    int start_node = 2;
    cout<< "start node: "<< start_node<< endl;
    get_dfs(graph, start_node);
    get_dfs_rec(graph, start_node);
    return 0;
}
