#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return 0;
        vector<int> left(len, 0),right(len, 0);
        left[0] = nums[0];
        right[len-1] = nums[len-1];
        for(int i=1; i<len; i++){
            left[i]+=left[i-1]+nums[i];
            right[len-1-i]+= right[len-i]+nums[len-1-i];
        }
        if(right[1]==0) return 0;
        for(int i=1; i<len-1;i++){
            if(left[i-1]==right[i+1]) return i;
        }
        return (left[len-2]==0)?len-1:-1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2,3,-1,8,4};
    cout<< obj.findMiddleIndex(nums)<< endl;
    return 0;
}
