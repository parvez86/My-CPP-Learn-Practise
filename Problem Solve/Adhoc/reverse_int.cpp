#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // naive
    int reverse(int x) {
        if(x==0 || x==-2147483648) return 0;
        bool is_neg = false;
        if(x<0) {is_neg=true; x=0-x;};
        int mult= 0;
        while(x>0) {
            if(mult > (INT_MAX-7)/10) return 0;
            mult = mult*10 + (x%10);
            x/=10;
        }
        if(is_neg) mult= 0 - mult;
        return mult;
    }
    // with recursion
    int reverse2(int x){
        if(x==0 || x==-2147483648) return -1;
        bool is_neg = false;
        if(x<0) {is_neg=true; x=0-x;};

        int mult = reverse_with_rec(x, 0);

        if(is_neg) mult= 0 - mult;
        return mult;
    }
    int reverse_with_rec(int x, int result){
        if(result > (INT_MAX-7)/10) return -1;
        if(x<10) return result*10+x;
        return reverse_with_rec(x/10, result*10+(x%10));
    }
};


int main()
{
    Solution ob;
    bool is_neg=false;
    int val = 2147483647;
    // int val = 2147483;
    cout<< val<< endl;
    cout<< ob.reverse(val)<< endl;
    if(val<0) is_neg = true;
    cout<< ob.reverse2(val)<< endl;
    return 0;
}

