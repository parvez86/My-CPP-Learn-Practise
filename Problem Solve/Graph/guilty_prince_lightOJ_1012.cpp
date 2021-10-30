#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define pb push_back
#define MAX 22
using namespace std;
vector<vector<bool>> vis(MAX, vector<bool> (MAX, false));
vector<vector<char>> vec(MAX, vector<char> (MAX, ' '));
queue<pair<int,int>> q;

void clear_vec(int row, int col)
{
    for(int i=0; i<row;i++){
        for(int j=0; j<col; j++){
            vis[i][j] = false;
           // vec[i][j] = ' ';
        }
    }
    return;
}

void check_vec(int row, int col)
{
    for(int i=0; i<row;i++){
        for(int j=0; j<col; j++){
            cout<< "i="<<i<<"j="<<j<<","<<vec[i][j]<< vis[i][j]<< " ";
           // vec[i][j] = ' ';
        }
        cout<<endl;
    }
    return;
}
int countCells(int init_x, int init_y, int row, int col)
{
    // parameters
    // nearest cells (x,y):
    // top(i-1, j), left(i, j-1), right(i, j+1), bottom(i+1, j)
    int x[]={-1, 0, 0, 1},y[]={0,-1,1, 0};
    // count prince's visited cells
    // count with initial cell
    int cnt=1;

    //root
    q.push(make_pair(init_x, init_y));
    vis[init_x][init_y] = true;

    while(!q.empty()){
        // for direction
        int temp_x= q.front().first;
        int temp_y= q.front().second;
        q.pop();
        for(int k=0;k<4; k++){
            int i=temp_x+x[k];
            int j=temp_y+y[k];
            if((i>=0 && i<row) && (j>=0 && j<col)){
                if(vec[i][j]!='#' && !vis[i][j]){
                    vis[i][j] = true;
                    q.push(make_pair(i, j));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void findLand(int t)
{
    int row, col;
    cin>> col>> row;

    clear_vec(row, col);

    char ch;
    int init_x,init_y;
    for(int i=0; i<row;i++){
        for(int j=0; j<col; j++){
            cin>> ch;
            vec[i][j] = ch;
            if(ch=='@') {init_x=i;init_y=j;}
        }
    }
    // check_vec(row, col);
    cout<< "Case "<< t<< ": ";
    cout<< countCells(init_x, init_y, row, col)<< endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>> t;
    for(int i=1; i<=t; i++){
        findLand(i);
    }
    return 0;
}