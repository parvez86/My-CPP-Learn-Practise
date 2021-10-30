#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, int> mp;
        vector<int> pair_vec;

        for(int i=0; i<nums.size(); i++){
            int temp = target-nums[i];
            auto indx = mp.find(temp);

            if(indx != mp.end()){
                if(indx->second<i){
                    pair_vec.push_back(indx->second);
                    pair_vec.push_back(i);
                }else{
                    pair_vec.push_back(i);
                    pair_vec.push_back(indx->second);
                }
                break;
            }
            mp[nums[i]] = i;
        }
        return pair_vec;
    }
    void print(vector<int>& vec){
        int len = vec.size()-1;
        cout<< "[";
        for(int i=0; i<len; i++) cout<< vec[i]<< ", ";
        if(len>=0) cout<< vec[len]<< "]";
    }
};


int main()
{
    Solution ob;
    vector<int> vec{2,7,11,15};
    vec = ob.twoSum(vec, 9);
    ob.print(vec);
    return 0;
}

