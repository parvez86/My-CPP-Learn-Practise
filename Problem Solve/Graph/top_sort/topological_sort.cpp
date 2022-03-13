#include <bits/stdc++.h>

using namespace std;
class Top_sort{
    vector<vector<int>> graph;
    vector<int> in_degree;
    void init_graph(int n){
        graph.resize(n, vector<int>());
        in_degree.resize(n, 0);
    }
public:
    void get_top_sort(int n, vector<vector<int>> edges)
    {
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
        int cnt=0;
        // store the nodes with top-order
        vector<int> result;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            cnt++;
            // remove the nodes from each connected nodes
            // decrease the in-degree of each connected nodes by 1
            for(int i=0; i<graph[node].size(); i++){
                int temp_node = graph[node][i];
                if(--in_degree[temp_node] == 0) q.push(temp_node);
            }
        }

        if(cnt != n) {cout<< "There exists a cycle in the graph"<< endl;return;}
        print_nodes(result);
    }

    void print_nodes(vector<int> nodes){
        cout<< "The topological order of nodes of the graph: ";
        for(const auto node:nodes) cout<< node<< " ";
        cout<< endl;
    }
};


int main()
{
    Top_sort obj;
    int n=6;
    vector<vector<int>> edges{
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };
    obj.get_top_sort(n, edges);
    return 0;
}
