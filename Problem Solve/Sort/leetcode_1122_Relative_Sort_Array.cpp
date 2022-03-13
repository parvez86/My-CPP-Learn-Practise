#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int flag[1001]={0};
        vector<int> result;
        for(int i=0; i<arr1.size(); i++) flag[arr1[i]]++;

        for(int i=0; i<arr2.size(); i++){
            int cnt = flag[arr2[i]];
            if(cnt != 0){
                flag[arr2[i]] = 0;
                while(cnt--) result.push_back(arr2[i]);
            }
        }
        //
        for(int i=1; i<1001; i++){
            if(flag[i]>0){
                int cnt = flag[i];
                while(cnt--) result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> res = obj.relativeSortArray(arr1, arr2);

    for(int it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
