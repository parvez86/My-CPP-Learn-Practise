#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MAX = 500001;
    vector<vector<int>> graph;

    void init_graph(){
        graph.resize(MAX, vector<int>());
    }

    bool compare(const pair<int, int>&a, const pair<int, int>&b)
    {
       return a.second<b.second;
    }

    int count_node(){
        int i=1;
        while(graph[i].size()>0) i++;
        return (i-1);
    }

    void insert_edge(int a, int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int get_centre(int n){
        for(int i=1; i<=n;i++){
            if(graph[i].size()==n-1) return i;
        }
        return 1;
    }
public:
    int findCenter(vector<vector<int>>& edges) {
        int edge_size = edges.size();
        int n = 0;
        // get max node
        for(int i=0; i<edge_size; i++){
            n = max({n, edges[i][0], edges[i][1]});
        }

        vector<vector<int>> graph(n+1, vector<int>());

        // insert edge
        for(int i=0; i<edge_size; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        // get max node
        for(int i=1; i<=n; i++){
            if(graph[i].size()==n-1) return i;
        }
        return 1;
    }

    int findCenter2(vector<vector<int>>& edges) {
        map<int, int> mp;
        for(int i=0; i<edges.size(); i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }

        for(auto it:mp){
            cout<< it.first<< " "<< it.second<< endl;
        }
        return max_element(mp.begin(), mp.end(), [](const pair<int,int>& a, const pair<int,int>& b)->bool{ return a.second < b.second;})->second;
    }

    int findCenter3(vector<vector<int>>& edges) {
        return (edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])?edges[0][0]:edges[0][1];
    }
};


int main()
{
    Solution obj;
    vector<vector<int>> edges{{1,2},{1,3},{5,1},{1, 4}};
    cout<< obj.findCenter2(edges)<< endl;
    return 0;
}
