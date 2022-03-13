#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<bool> visited;
    void init_graph(int n){
        visited.resize(n, false);
    }
    void dfs(int start_node, int end_node, vector<vector<int>>& graph, vector<int>path){
        visited[start_node] = true;
        // add current node
        path.push_back(start_node);

        // if current node is the end node
        // store the path
        if(start_node==end_node) result.push_back(path);


        for(int i=0; i<graph[start_node].size(); i++){

            // if current node is not visited
            // visit it
            if(!visited[graph[start_node][i]]){
                int temp = graph[start_node][i];
                visited[temp] = true;
                dfs(temp, end_node, graph, path);
            }
        }
        // backtracking
        // remove the node from visited node & path
        visited[start_node] = false;
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        init_graph(graph.size());

        //
        dfs(0, graph.size()-1, graph, vector<int>());
        return result;
    }
    void print_paths(vector<vector<int>> paths){
        cout<< "The paths are: [";
        for(int i=0; i< paths.size(); i++){
            cout<< "[";
            for(int j=0; j<paths[i].size(); j++) {
                cout<< paths[i][j];
                if(j != paths[i].size()-1) cout<< ",";
            }
            cout<< "]";
            if(i != paths.size()-1) cout<< ",";
        }
        cout<< "]"<< endl;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> graph{
        {4,3,1},{3,2,4},{3},{4},{}
    };
    vector<vector<int>> paths = obj.allPathsSourceTarget(graph);
    obj.print_paths(paths);
    return 0;
}
