#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist=0;
        while(x>0 || y>0){
            if(x>0 && y>0) {
                if((x&1)!=(y&1)) dist++;
                x>>=1;
                y>>=1;
            }else if(y>0 && y&1) {dist++; y>>=1;}
            else if(x>0 && x&1){dist++; x>>=1;}
            else {
                x>>=1;
                y>>=1;
            }
            cout<< dist<< endl;
        }
        return dist;
    }
};


int main()
{
    Solution obj;
    int x=19, y=3;
    cout<< obj.hammingDistance(x, y)<< endl;
    return 0;
}
