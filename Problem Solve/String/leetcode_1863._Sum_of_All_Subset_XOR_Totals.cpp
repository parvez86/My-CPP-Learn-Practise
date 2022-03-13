#include <bits/stdc++.h>

using namespace std;

class Solution {
    int getSubSets(vector<int>& nums, int indx, vector<int> subsets){
        int sum;
        if(indx == nums.size()){
            int sub_xor = 0;
            for(int i=0; i<subsets.size(); i++) sub_xor^=subsets[i];

            sum = sub_xor;
        }else{
            // 1 -> with the index value
            // 0 -> without the index vale
            vector<int> cnd = {0,1};
            for(int i=0; i< cnd.size(); i++ ){
                if(cnd[i]==1){
                    subsets.push_back(nums[indx]);
                    sum += getSubSets(nums, indx+1, subsets);
                    subsets.pop_back();
                }else{
                    sum += getSubSets(nums, indx+1, subsets);
                }
            }
        }
        return sum;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return getSubSets(nums, 0, {});
    }
};

int main()
{
    Solution obj;
    vector<int> vec = {1, 3};

    cout<< obj.subsetXORSum(vec)<< endl;
    return 0;
}
