#include <bits/stdc++.h>

using namespace std;

class Solution {
    priority_queue<int, vector<int>, greater<int> > pq;
    int kth;
public:
    void KthLargest(int k, vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len ; i++) pq.push(nums[i]);
        kth = k;
        while(pq.size() > k) pq.pop();
    }

    int add(int val){
        pq.push(val);
        if(pq.size()>kth) pq.pop();
        return pq.top();
     }
};

int main()
{
    Solution obj;
    int arr[] = {3,1,4,NULL,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums(arr, arr+len);
    int k = 1;
    obj.KthLargest(k, nums);
    cout<< obj.add(5)<< endl;
    return 0;
}

