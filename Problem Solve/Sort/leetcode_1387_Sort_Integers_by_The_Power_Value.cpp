#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;
        for(int i=lo; i<=hi; i++){
            int pow = 0;
            int p=i;
            while(p>1){
                p = (p%2==0)?p/2:p*3+1;
                pow++;
            }
            nums.push_back(make_pair(pow, i));
        }
        sort(nums.begin(), nums.end());
        return nums[k-1].second;
    }
    int getKth2(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=lo; i<=hi; i++){
            int pow = 0;
            int p=i;
            while(p>1){
                p = (p%2==0)?p/2:p*3+1;
                pow++;
            }
            pq.push(make_pair(pow, i));
        }
        k--;
        while(k--) pq.pop();
        return pq.top().second;
    }
};

int main()
{

    Solution obj;
    int lo = 7, hi=15, k=5;
    cout<< obj.getKth(lo, hi, k)<< endl;
    cout<< obj.getKth2(lo, hi, k)<< endl;
    return 0;
}
