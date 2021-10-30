#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define pb push_back
#define MAX 20001
using namespace std;
vector<int> visited(MAX, -1);
vector<vector<int>> vec(MAX, vector<int>());
set<int> st;
queue<int> q;

void insertEdge(int a, int b)
{
    vec[a].pb(b);
    vec[b].pb(a);
}

void clear_vec()
{
    for(auto it = st.begin(); it != st.end(); it++){
        visited[*it]=-1;
        vec[*it].clear();
    }
    st.clear();
    return;
}

// count rivals with bfs
int countRivals(int curr)
{
    int cnt_vam=0,cnt_lik=0;
    q.push(curr);
    // suppose flag=0 for vampire
    // flag=1 for lykens
    visited[curr]=0;
    cnt_vam++;
    while(!q.empty()){
        curr= q.front();
        q.pop();
        int len=vec[curr].size();
        for(int i=0; i<len; i++){
            int temp = vec[curr][i];
            if(visited[temp]==-1){
                visited[temp] = 1-visited[curr];
                // count vampire
                if(visited[temp]==0) cnt_vam++;
                //count lyken
                else cnt_lik++;
                q.push(temp);
            }
        }
    }
    if(cnt_vam>cnt_lik) return cnt_vam;
    return cnt_lik;
}
void getRivals(int n, int t)
{
    clear_vec();
    int a,b,cnt=0;
    for(int i=0;i<n; i++){
        cin>> a>> b;
        insertEdge(a,b);
        st.insert(a);
        st.insert(b);
    }
    // if graph is disconnected
    for(auto it=st.begin(); it!=st.end(); it++){
        if(visited[*it]==-1){
            cnt+=countRivals(*it);
        }
    }
    cout<< "Case "<< t<< ": "<< cnt<< endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>> t;
    for(int i=1; i<=t; i++){
        int n;
        cin>> n;
        getRivals(n, i);
    }
    return 0;
}
