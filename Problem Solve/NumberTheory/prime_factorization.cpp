#include <iostream>
#include <vector>
#include <cmath>
#define P_MAX 1000000

using namespace std;

void seive(vector<int>& primes)
{
    // vector<bool> primes(P_MAX, true);
    primes[0] = 0;
    primes[1] = 1;
    primes[2] = 2;
    for(int i=4; i<=P_MAX; i+=2) primes[i] = 2;
    for(int i=3; i<=P_MAX; i+=2){
        if(primes[i] == -1){
            primes[i] = i;
            for(int j=i+i; j<=P_MAX; j+=i){
                if(primes[j] == -1) primes[j] = i;
            }
        }
    }
    return;
}

void get_prime_fact(vector<int> primes, int val)
{
    cout<< "The factors of "<< val<< " are: ";
    while(val>1){
        cout<< primes[val]<< " ";
        val/=primes[val];
    }
    cout<< endl;
}

void get_prime_fact2(int val)
{
    int root= sqrt(val);
    cout<< "The factors of "<< val<< " are: ";
    while(val%2==0){
        cout<< 2<< " ";
        val/=2;
    }
    for(int i=3; i<=root; i+=2){
        while(val%i==0){
            cout<< i<<" ";
            val/=i;
        }
    }

    if(val>2) cout<< val<< endl;
    cout<< endl;
    return;
}

int main()
{
    vector<int> primes(P_MAX, -1);
    seive(primes);
    int val = 3587;
    get_prime_fact(primes, val);
    get_prime_fact2(val);
    return 0;
}
