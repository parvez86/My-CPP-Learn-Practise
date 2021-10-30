#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        cout<< "[";
        int len = nums.size();
        if(len==1) {cout<< nums[0]<< "]" << endl;return;}
        for(int i=len-1;i>0;i--){
            if(nums[i]> nums[i-1]) {
                int j=i;
                while(j+1<len) {
                        if (nums[j+1]>nums[i-1] && nums[j+1]<=nums[j]) j++;
                        else break;
                }
                swap(nums[j], nums[i-1]);
                if(i<len-1) sort(nums.begin()+i, nums.end());
                for(int j=0; j<len-1; j++) cout<< nums[j]<<",";
                cout<< nums[len-1]<< "]"<< endl;
                return;
            }
        }
        sort(nums.begin(), nums.end());

        for(int i=0; i<len-1; i++){
            cout<< nums[i]<< ",";
        }
        cout<< nums[len-1]<< "]"<< endl;
        return;
    }
    void nextPermutation2(vector<int>& nums){
        int len = nums.size();
        next_permutation(nums.begin(), nums.end());
        cout<< "[";
        for(int i=0; i<len-1; i++){
            cout<< nums[i]<< ",";
        }
        cout<< nums[len-1]<< "]"<< endl;
    }
};


int main()
{
    Solution ob;
    // vector<int> vec{2, 1, 4, 3};
    vector<int> vec{4, 3, 2, 1};
    vector<int> vec1(vec);
    // naive function
    ob.nextPermutation(vec);
    // using built-in function
    ob.nextPermutation2(vec1);
    return 0;
}

