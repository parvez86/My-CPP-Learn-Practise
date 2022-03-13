#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum^=nums[i];
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr={2,2,1};
    cout<< obj.singleNumber(arr)<< endl;
    return 0;
}
