#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        cout<< "[";
        vector<vector<int>> res_nums;
        int len = nums.size();
        if(len==1) {cout<< "["<< nums[0]<< "]]" << endl; res_nums.push_back(nums); return res_nums;}

        sort(nums.begin(), nums.end());
        int permute_number = count_fact(len), j=1;
        do{
            cout<< "[";
            res_nums.push_back(nums);
            for(int i=0; i<len-1; i++){
                cout<< nums[i]<< ",";
            }
            if(j==permute_number) {cout<< nums[len-1]<< "]"; continue;}
            cout<< nums[len-1]<< "],";
            j++;
        }while(next_permutation(nums.begin(), nums.end()));
        cout<< "]"<< endl;
        return res_nums;
    }

    // custome next_permutation
    bool nextPermutation(vector<int>& nums) {
        int len = nums.size();
        // find rightmost index where arr[i] > arr[i-1] (swap point) // 1, 2*, 4, 3
        // find another second point: nearest big at right side // 1, 2, 4, 3*
        // swap the two node & sort ascending order from index i+1 to end   // 1, 3*, 4, 2* -> 1, 3, 2*, 4*
        for(int i=len-1;i>0;i--){
            if(nums[i]> nums[i-1]) {
                int j=i;
                // the break point, i-1 is the leftmost swap val
                while(j+1<len) {
                        if (nums[j+1]>nums[i-1] && nums[j+1]<=nums[j]) j++;
                        else break;
                }
                // swaping
                swap(nums[j], nums[i-1]);
                // sort the rest in ascending order
                if(i<len-1) sort(nums.begin()+i, nums.end());
                return true;
            }
        }
        return false;
    }

    int count_fact(int num){
        if(num==1) return 1;
        return num*count_fact(num-1);
    }
};


int main()
{
    Solution ob;
    vector<int> vec{1, 3, 2};
    ob.permute(vec);
    return 0;
}

