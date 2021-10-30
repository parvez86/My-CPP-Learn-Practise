#include <iostream>
#include <vector>
#include <cmath>
#define P_MAX 1000000

using namespace std;

// complexity: 0(nloglogn)
void seive(vector<bool>& primes)
{
    // 0 & 1 are non-prime
    primes[0] = primes[1] = false;

    // mark all multiples of 2
    for(int i=4; i<=P_MAX; i+=2) primes[i] = false;

    //
    for(int i=3; i<=P_MAX; i+=2){
        // if the number is prime
        if(primes[i]){
            // mark all multiples of the prime
            // if value is true, then make it false
            for(int j=i+i; j<=P_MAX; j+=i){
                if(primes[j]) primes[j] = false;
            }
        }
    }
    return ;
}

void seive2(vector<int>& primes)
{
    // vector<bool> primes(P_MAX, true);
    primes[0] = primes[1] = 0;
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

// with seive
bool check_prime(vector<bool> primes, int val)
{
    return primes[val];
}

// complexity: O(log n)
bool check_prime2(int val)
{
    if(val<=1 || (val != 2 && !(val&1))) return false;

    int root = sqrt(val);
    //for(int i=3; i*i<= val; i+=2){
    for(int i=3; i<=root; i+=2){
        if(val%i == 0) return false;
    }
    return true;
}

//
bool check_prime3(vector<int> primes, int val)
{
    return (val != 0 && primes[val]==val);
}

int main()
{
    int val= 5987;
    vector<bool> primes(P_MAX, true);
    vector<int> primes2(P_MAX, -1);
    seive(primes);
    seive2(primes2);
    (check_prime(primes, val))? cout<< "Prime"<<endl:cout<< "Not prime"<< endl;
    (check_prime2(val))? cout<< "Prime"<<endl:cout<< "Not prime"<< endl;
    (check_prime3(primes2, val))? cout<< "Prime"<<endl:cout<< "Not prime. It is divisible by "<< primes2[val]<< endl;
    return 0;
}
