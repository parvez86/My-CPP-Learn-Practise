#include <bits/stdc++.h>

using namespace std;

class Solution {
    void get_subsets(vector<int>& nums, int max_or, int indx, int curr, int& res){
        if(curr==max_or) res++;

        for(int i=indx; i<nums.size(); i++){
            get_subsets(nums, max_or, i+1, curr|nums[i], res);
        }
    }

    int get_subsets2(vector<int>& nums, int mx_or, int indx, int curr){
        if(indx==nums.size()) return curr==mx_or;
        if(curr==mx_or) return 1<< (nums.size()-indx);
        return get_subsets2(nums, mx_or, indx+1, curr|nums[indx])+
        get_subsets2(nums, mx_or, indx+1, curr);    // pick & non-pick
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();

        // get max-xor
        int mx_or = 0, res=0;
        for(auto it:nums) mx_or |= it;

        // generate subsets
        get_subsets(nums, mx_or, 0, 0, res);
        return res;
    }

    int countMaxOrSubsets2(vector<int>& nums) {
        int mx=0;
        int dp[1<< 17] = {1};
        //
        for(auto it:nums){

            for(int i=mx; i>=0; --i){
                dp[i | it] += dp[i];
            }
            mx |= it;
        }
        return dp[mx];
    }

    int countMaxOrSubsets3(vector<int>& nums) {
        int n=nums.size();

        // get max-xor
        int mx_or = 0, res=0;
        for(auto it:nums) mx_or |= it;

        // generate subsets
        return get_subsets2(nums, mx_or, 0, 0);
    }
};

int main()
{
    Solution obj;
    vector<int> vec={3,2,1,5};

    cout<< obj.countMaxOrSubsets(vec)<< endl;
    cout<< obj.countMaxOrSubsets2(vec)<< endl;
    cout<< obj.countMaxOrSubsets3(vec)<< endl;
    return 0;
}
