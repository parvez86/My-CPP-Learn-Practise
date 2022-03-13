#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    uint32_t reverseBits(uint32_t n){
        uint32_t mask=0;
        int t=32;
        while(t){
            mask = (mask << 1) | (n&1);
            n >>=1;
            t--;
        }
        return mask;
    }

    uint32_t reverseBits2(uint32_t n){
        uint32_t res = 0;
        for(int i=31; i>=0; i--){
            res <<=1;
            if(n&(1<<(31-i))) res |=1;
        }
        return res;
    }
};

int main()
{
    Solution obj;
    uint32_t n = 11111111111111111111111111111101;
    cout<< obj.reverseBits(n)<< endl;
    cout<< obj.reverseBits2(n)<< endl;
    return 0;
}

