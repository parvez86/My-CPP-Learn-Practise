#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int find_item(int arr[], int val, int len)
{
    for(int i=0; i<len; i++){
        if (arr[i]==val) return i;
    }
    return -1;
}

// naive
void find_duplicate(int arr[], int len)
{
    // store the number of repeat
    int flag[len]={0};
    // store the item
    int item[len], max_indx=0;
    for(int i=0; i<len; i++){
        int indx = find_item(arr, arr[i], max_indx);
        if(indx == -1){
            arr[max_indx++] = arr[i];
        }else{
            flag[indx]++;
        }
    }

    // display duplicate
    cout<< "The duplicate items are: ";
    for(int i=0; i<max_indx; i++){
        if(flag[i]>0){
            cout<< arr[i]<< " ";
        }
    }
    cout<< endl;
}

// using vector and queue
void find_duplicate2(vector<int> vec)
{
    queue<int> q;
    int len = vec.size();
    bool flag;
    for(int i=0; i<len-1; i++){
        flag = false;
        if(vec[i] != 0){
            for(int j=i+1; j<len; j++ ){
                if(vec[i]==vec[j]){
                    if(!flag) flag=true;
                    vec[j]^=vec[i];
                }
            }
            if(flag) q.push(vec[i]);
            vec[i]= 0;
        }
    }
    cout<< "The duplicate items are: ";
    while(!q.empty()){
        cout<< q.front()<< " ";
        q.pop();
    }
    cout<< endl;
}

// using map
void find_duplicate3(vector<int> vec)
{
    map<int, int> mp;
    int len = vec.size();
    for(int i=0; i<len; i++){
        mp[vec[i]]++;
    }
    cout<< "The duplicate items are: ";
    for(auto it:mp){
        if(it.second >1) cout<< it.first<<" ";
    }
    cout<< endl;
    mp.clear();
}


int main()
{
    int arr[] = {2, 3, 5, 1, 5, 6, 7, 2, 6, 8};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr+len);
    find_duplicate(arr, len);
    find_duplicate2(vec);
    find_duplicate3(vec);
    return 0;
}

