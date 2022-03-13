#include <bits/stdc++.h>
#define MAX 33

using namespace std;

class Solution {
    vector<bool> Prime;
    void init(){
        Prime.resize(MAX, true);
    }
    void seive(){
        init();
        Prime[0] = false;
        Prime[1] = false;
        for(int i=4; i<MAX; i+=2) Prime[i] = false;
        for(int i=3; i<MAX; i+=2){
            if(Prime[i]){
                for(int j=i+i; j<MAX; j+=i) if(Prime[j]) Prime[j] = false;
            }
        }
    }
    bool isPrime(int p){
        if(p==1) return false;
        if(p>2 && p%2==0) return false;
        for(int i=3; i*i<=p; i+=2) if(p%i==0) return false;
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        seive();
        int cnt=0;
        bitset<32> b;
        for(int i=left; i<=right; i++){
            b = i;
            // cout<< b<< " "<< b.count()<< endl;
            if(Prime[b.count()]) cnt++;
        }
        return cnt;
    }

    int countPrimeSetBits2(int left, int right) {
        int cnt=0;
        bitset<32> b;
        for(int i=left; i<=right; i++){
            b = i;
            // cout<< b<< " "<< b.count()<< endl;
            if(isPrime(b.count())) cnt++;
        }
        return cnt;
    }
};


int main()
{
    Solution obj;
    int left=6, right=100;
    cout<< obj.countPrimeSetBits(left, right)<< endl;
    cout<< obj.countPrimeSetBits2(left, right)<< endl;
    return 0;
}
