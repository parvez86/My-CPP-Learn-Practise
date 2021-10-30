#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());

        // sort 2nd array
        sort(nums2.begin(), nums2.end());

        // merge 2 array
        int indx1=0, indx2=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> nums;
        int len = len1+len2;
        for(int i=0; i<len;i++){
            if(indx1>=len1) nums.push_back(nums2[indx2++]);
            else if(indx2>=len2) nums.push_back(nums1[indx1++]);
            else if(nums1[indx1] <= nums2[indx2]) nums.push_back(nums1[indx1++]);
            else nums.push_back(nums2[indx2++]);
            if(indx1>= len1 && indx2>= len2) break;
        }
        if(len%2==0) return (nums[len/2-1]+ nums[(len/2)])*1.0/2;
        return nums[len/2];
    }
};

int main()
{
    Solution ob;
    vector<int> vec1{1,2}, vec2{3, 4};
    cout<< ob.findMedianSortedArrays(vec1, vec2)<< endl;
    return 0;
}
