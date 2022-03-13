#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        int len= arr.size();
        for(int i=0; i<len-1; i++){
            int sum=arr[i];
            for(int k=i+1; k<len; k++){
                if((sum^=arr[k])==0) {cnt+=k-i;}

            }
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    vector<int> arr={2,3,1,6,7};
    cout<< obj.countTriplets(arr)<< endl;
    return 0;
}
