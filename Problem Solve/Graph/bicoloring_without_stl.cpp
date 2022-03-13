#include <iostream>
#define MAX 201
using namespace std;

int color[MAX];
bool edge[MAX][MAX];
int E, V;


class Queue{
public:
    int num_elems,q_front,q_end;
    int arr[MAX];
    Queue(){
        num_elems=0;
        q_front=0;
        q_end=0;
        for(int i=0; i<MAX; i++)
            arr[i]=-1;
    }
    bool isEmpty(){
        if(num_elems==0)
            return true;
        else
            return false;
    }

    void enqueue(int x){
        arr[q_end++]=x;
        num_elems++;
    }

    int dequeue(){
        num_elems--;
        return arr[q_front++];
    }
};

void reset(int num_max){
    for(int i=0; i<num_max; i++){
        for(int j=0; j<num_max;j++)
            edge[i][j]= false;
        color[i]=-1;
    }
}

bool isBipart(int src){
    color[src]=1;
    Queue q;
    q.enqueue(src);

    while(!q.isEmpty()){
        int node=q.dequeue();
        if(edge[node][node]){
            return false;
        }
        for(int i=0; i<V; i++){
            if(edge[node][i]){
                if(color[i]==-1){
                    color[i]=1-color[node];
                    q.enqueue(i);
                }else if(color[i]==color[node]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    while(cin>> V && V!=0){
        reset(V);
        cin>> E;

        for(int i=0; i<E; i++){
        int x,y;
        cin>>x>>y;
        edge[x][y]=true;
        }
        (isBipart(0))? cout<< "BICOLORABLE."<< endl:cout<< "NOT BICOLORABLE."<< endl;
    }
}
