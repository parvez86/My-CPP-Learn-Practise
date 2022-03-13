#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size(), cnt=0;
        vector<bool> visited(len, false);

        // dfs
        stack<int> st;
        st.push(0);
        visited[0] = true;
        while(!st.empty()){
            int room = st.top();

            st.pop();
            cnt++;

            for(int i=0; i< rooms[room].size(); i++){
                if(!visited[rooms[room][i]]) {
                    st.push(rooms[room][i]);
                    visited[rooms[room][i]] = true;
                }
            }
        }
        return cnt==len;
    }

    bool canVisitAllRooms2(vector<vector<int>>& rooms) {
        int len = rooms.size(), cnt=0;
        vector<bool> visited(len, false);

        //bfs
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int room = q.front();

            q.pop();
            cnt++;

            for(int i=0; i< rooms[room].size(); i++){
                if(!visited[rooms[room][i]]) {
                    q.push(rooms[room][i]);
                    visited[rooms[room][i]] = true;
                }
            }
        }
        return cnt==len;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> rooms{
        {1, 2}, {2, 1}, {1}
    };
    (obj.canVisitAllRooms(rooms))?cout<< "True"<< endl:cout<< "False"<< endl;
    (obj.canVisitAllRooms2(rooms))?cout<< "True"<< endl:cout<< "False"<< endl;
    return 0;
}
