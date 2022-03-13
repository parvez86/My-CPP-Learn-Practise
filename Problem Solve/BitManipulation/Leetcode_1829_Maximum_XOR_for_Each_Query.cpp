#include <bits/stdc++.h>

using namespace std;

class Solution {
    int pow(int m, int i){
        if(i==1) return m;
        return m*pow(m,i-1);
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = pow(2,maximumBit)-1;
        int sum=0;
        vector<int> res(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) sum^=nums[i];
        for(int i=0; i<nums.size(); i++){
            res[i]=sum^k;
            sum^=nums[nums.size()-1-i];
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> vec={0, 1, 1, 3};
    int k=2;
    vector<int> res = obj.getMaximumXor(vec, k);
    for(auto it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
