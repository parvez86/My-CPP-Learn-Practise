#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define pb push_back
#define MAX 10001
using namespace std;
vector<int> visited(MAX, -1);
vector<int> TTL(MAX, -1);
vector<vector<int>> nodes(MAX, vector<int>());

void insertEdge(int a, int b)
{
    nodes[a].pb(b);
    // for bidirectional
    nodes[b].pb(a);
    return;
}

void clear_vec(int mn, int mx)
{
    for(int i=mn;i<=mx;i++) {visited[i]=-1;TTL[i]=-1;nodes[i].clear();}
}

int getNodeNumber(int i, int ttl)
{
    queue<int> q;
    q.push(i);
    visited[i] = 0;
    TTL[i] = ttl;
    int cnt=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i <nodes[node].size(); i++){
            int temp = nodes[node][i];
            if(visited[temp]==-1){
                visited[temp] = 0;
                TTL[temp] = TTL[node]-1;
                if(TTL[temp]>-1) cnt++;
                else return cnt;
                q.push(temp);
                continue;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, e, cs=1;
    while(cin>> n && n!=0){
        set<int> st;
        int a, b;
        for(int i=0; i<n; i++){
            cin>> a>> b;
            st.insert(a);
            st.insert(b);
            insertEdge(a, b);
        }
       // cout<< endl;
        int mn = *st.begin();
        int mx = *st.rbegin();
        while(true){
            cin>> a>> b;
            if(a==0 && b==0) break;

            for(int i=mn; i<=mx; i++){visited[i]=-1; TTL[i]=-1;}
            int cnt = getNodeNumber(a,b);
            cout<< "Case "<< cs<<": " << st.size()-cnt<< " nodes not reachable from node "<< a<< " with TTL = "<< b<< "."<< endl;
            cs++;
        }
        clear_vec(mn, mx);
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                