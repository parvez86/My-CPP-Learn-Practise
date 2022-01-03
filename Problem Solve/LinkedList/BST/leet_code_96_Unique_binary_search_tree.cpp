#include <bits/stdc++.h>
using namespace std;

class Solution {
    // formula: 2n!/(n!n!) =
    // 2n*(2n-1)*(2n-2)*.....*(n+1) *1
    //----------------------------- ---
    // n * (n-1) * (n-2)*..... *1   *0
    long long get_catalan(int n, int r){
        if(r == 0) return 1;
        return  (n * get_catalan(n-1, r-1))/r;
    }
public:
    // using dp
    int numTrees(int n) {
        vector<int> nums(n+1, 0);
        nums[0] = nums[1] = 1;
        //
        // nums[i] = sum (nums[j]*nums[j_max-j])    j_max=i-1
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                nums[i]+= nums[j]*nums[i-1-j];
            }
        }
        return nums[n];
    }
    // using recursion
    int numTrees2(int n) {
        // formula
        // C_n = 2n!/((n+1)!n!) = 1/(n+1)[2n!/(2n-n)!n!]
        return (int)(get_catalan(n+n, n)/(n+1));
    }
};

int main()
{
    Solution obj;
    int n=5;
    cout<< obj.numTrees(n)<< endl;
    return 0;
}
