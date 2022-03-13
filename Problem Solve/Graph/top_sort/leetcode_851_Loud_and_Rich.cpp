#include <bits/stdc++.h>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& quiet, vector<int>& ans, int node){
        ans[node] = node;

        for(auto child:graph[node]){
            if(ans[child]==-1) dfs(graph, quiet, ans, child);
            if(quiet[ans[child]]<quiet[ans[node]]) ans[node] = ans[child];
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> answer(n, -1);

        for(auto edge:richer){
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            if(answer[i]==-1) dfs(graph, quiet, answer, i);
        }
        return answer;
    }


    vector<int> loudAndRich2(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> answer(n, -1);
        vector<int> inDegree(n, 0);
        queue<int> q;

        for(auto edge:richer){
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        for(int i=0; i<n;i++){
            if(inDegree[i]==0) {q.push(i);}
            answer[i]= i;
        }

        // khan's algo
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int child:graph[node]){
                if(quiet[answer[child]] > quiet[answer[node]]) answer[child] = answer[node];
                if(--inDegree[child]==0) q.push(child);
            }
        }


        return answer;
    }
};


int main()
{
    Solution obj;
    vector<vector<int>> richer = {
        {1,0}, {2,1}, {3,1}, {3,7}, {4,3}, {5,3}, {6,3}
    };
    vector<int> quiet = {3,2,5,4,6,1,7,0};

    vector<int> res = obj.loudAndRich(richer, quiet);

    for(int it:res) cout<< it<< " ";
    cout<< endl;

    vector<int> res2 = obj.loudAndRich2(richer, quiet);

    for(int it:res2) cout<< it<< " ";
    cout<< endl;
    return 0;
}
