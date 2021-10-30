#include <iostream>

using namespace std;

int check_pow_of_2(int n){
    while(n>1){
        if(n%2==1) return 0;
        n/=2;
    }
    if (n==1) return 1;
    return 0;
}

// using recursion
// 1 -> true, 0 -> false
//
int check_pow_of_2_rec(int n)
{
    //cout<< n<< endl;
    if(n==1) return 1;
    if(n%2==1 || n==0) return 0;
    check_pow_of_2_rec(n/2);
}


//using bitwise
//2^n -> leftmost bit 1 & the rest is 0
int check_pow_of_2_bitwise(int n)
{
    return (n!=0) && (!(n&(n-1)));
}

int main()
{
    // Check if the number is power of 2
    int n;
    cout<< "Enter the number: ";
    cin>> n;

    (check_pow_of_2(n))? cout<< "The number is power of 2"<<endl:cout<<"The number is not power of 2"<< endl;
    (check_pow_of_2_rec(n))? cout<< "The number is power of 2"<<endl:cout<<"The number is not power of 2"<< endl;
    (check_pow_of_2_bitwise(n))? cout<< "The number is power of 2"<<endl:cout<<"The number is not power of 2"<< endl;
    return 0;
}
