#include <bits/stdc++.h>

using namespace std;


class Solution {

    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int dest){
        if(node == dest) return true;

        visited[node] = true;
        for(int neiv:graph[node]){
            if(!visited[neiv]){
                if(dfs(graph, visited, neiv, dest)) return true;
            }
        }
        return false;
    }

    bool get_top_sort(vector<vector<int>>& graph, int numCourse, int start, int end){
        vector<bool> vis(numCourse, false);
        while(!vis[start]){
            vis[start] = true;
            cout<< start<< " "<< vis[start]<< " " << graph[start][1]<< " "<< graph[start][1]<< endl;
            if(start != end && !vis[graph[start][1]]) start = graph[start][1];
        }
        return vis[end];
    }

    int findIndx(vector<int> arr, int indx, int num){
        if(arr.size()<=indx) return -1;
        if(arr[indx] == num) return indx;
        return findIndx(arr, indx+1, num);
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        if(prerequisites.size()==0) return ans;

        vector<vector<int>> graph(numCourses, vector<int>());
        for(auto it:prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        for(int i=0; i<queries.size(); i++){
            vector<bool> vis(numCourses, false);
            ans.push_back(dfs(graph, vis, queries[i][0], queries[i][1]));
        }
        return ans;
    }

    vector<bool> checkIfPrerequisite2(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<bool> vis(numCourses, false);
        if(prerequisites.size()==0) return ans;

        for(int i=0; i<ans.size(); i++){
            if(get_top_sort(prerequisites, numCourses, queries[i][0], queries[i][1])) ans[i] = true;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> prerequisities = {
        // {1,0}
        //{1,0},{1,2}
       // {1,2},{1,0},{2,0}
        {2,3},{2,1},{0,3},{0,1}
    };

    vector<vector<int>> queries = {
        // {0, 1}, {1, 0}, {1,2}
        // {1, 0}, {1, 2}
       // {0, 1}, {1, 0}
        {0, 1}, {0, 3}, {2, 3}, {3, 0}, {2, 0}, {0, 2}
    };

    int numCourses = 4;

    vector<bool> res = obj.checkIfPrerequisite(numCourses, prerequisities, queries);

    for(int it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
