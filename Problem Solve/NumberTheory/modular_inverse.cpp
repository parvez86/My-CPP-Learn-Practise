#include <iostream>
#include <cmath>

using namespace std;


int getGCD(int b, int m)
{
    if(m==0) return b;
    return getGCD(m, b%m);
}

// r = x^p mod m
int getPow(int x, int p, int m)
{
    if(p==0) return 1;
    int res = getPow(x, p/2, m) % m;
    res = (res*res) % m;
    if(p%2==1) res = (res * x) % m;
    return res;
}

int get_ext_gcd(int m, int b, int *x, int *y)
{
    if(m==0){
        *x=0; *y=1;
        return b;
    }
    int x1, y1;
    int d = get_ext_gcd(b%m, m, &x1, &y1);
    *x = y1 - (b / m) * x1;
    *y = x1;
    return d;
}

int getInverse(int b, int m)
{
   //  b %= m;
    for(int x=1; x<m; x++){
        int t = b*x;
        cout<< t<< " "<< m<< endl;
        if( t% m == 1) return x;
    }

    return -1;
}

// naive
void get_modular_inverse(int b, int m)
{
    int res = getInverse(b, m);
    (res==1)? cout<< "Modular inverse: "<< res<< endl:
        cout<< "Modular inverse: not exist"<< endl;
}

// using extended euclidean
// works only when b & m are co-prime
// complexity: O(m)
void get_modular_inverse_egcd(int b, int m)
{
    int x, y;
    int inv = get_ext_gcd(b, m, &x, &y);
    //
    (inv==1)? cout<< "Modular inverse: "<< (x%m+m)%m<< endl:
        cout<< "Modular inverse: not exist"<< endl;
}


// using Fermat's little theorem
// when m prime
// Complexity: O(log m)

void get_modular_inverse_fermat(int b, int m)
{
    int gcd = getGCD(b, m);
    if(gcd == 1){
        // if b, m are co-prime
        // b^-1 mod m = b^(m-2) mod m
        cout<< "Modular inverse: "<< getPow(b, m-2, m)<< endl;
    }else{
        cout<< "Modular inverse: not exist"<< endl;
    }
}

int main()
{
    int a = 10, b = 7;
    get_modular_inverse(a, b);
    get_modular_inverse_egcd(a, b);
    get_modular_inverse_fermat(a, b);
    return 0;
}
