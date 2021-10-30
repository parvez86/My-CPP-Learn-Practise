#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
#define MAX 201
using namespace std;
vector<int> visited(MAX, -1);
vector<vector<int>> nodes(MAX, vector<int>());

void insertEdge(int a, int b)
{
    nodes[a].pb(b);
    // for bidirectional
    nodes[b].pb(a);
    return;
}

void clear_vec(int n)
{
    for(int i=0;i<n;i++) {visited[i]=-1;nodes[i].clear();}
}

bool isBipartite(int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i <nodes[node].size(); i++){
            int temp = nodes[node][i];
            if(visited[temp]==-1){
                visited[temp] = 1-visited[node];
                q.push(temp);
                continue;
            }
            if(visited[temp]==visited[node]) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, e;
    while(scanf("%d", &n) && n!=0){
        clear_vec(n);
        scanf("%d", &e);
        for(int i=0; i<e; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            insertEdge(a,b);
        }
        (isBipartite(0))?printf("BICOLORABLE.\n"):printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
