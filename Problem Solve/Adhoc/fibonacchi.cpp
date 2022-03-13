#include <bits/stdc++.h>

using namespace std;
//long int sum;

// using recursion
// complexity: O(1), space complexity: O(n) [for stack]
void get_fibo_seq(int n)
{
    static long int num1=0, num2=1, sum;
    if(n>0){
        sum = num1 + num2;
        printf("%ld ",sum);
        num1 = num2;
        num2 = sum;
        get_fibo_seq(n-1);
    }
}


// complexity: O(n)
void get_fibo_seq2(int n)
{
    long int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    if(n == 0) {printf("%d\n", arr[n]);return;}
    if(n == 1) {printf("%d %d\n", arr[n-1], arr[n-2]);return;}
    for (int i = 2; i<=n; i++){
        arr[i]= arr[i-1]+ arr[i-2];
        printf("%ld ", arr[i]);
    }
}


// complexity: O(n),
void get_fibo_seq3(int n)
{
    long int val1 = 0;
    long int val2 = 1;
    if(n < 0) {printf("%ld\n", val1);return;}
    else if(n == 0) {printf("%ld %ld\n", val1, val2);return;}
    else {
        printf("0 1 ");
        for (int i = 1; i<=n; i++){
            long int sum = val1+val2;
            printf("%ld ", sum);
            val1 = val2;
            val2 = sum;
        }
    }
}


int get_fibo(int n, int m, int p){
    if(p == 0) return n;
    return get_fibo(n+m, n, p-1);
}


int get_fibo_seq4(int n)
{
    if(n==0 || n==1) return n;
    return get_fibo_seq4(n-1) + get_fibo_seq4(n-2);
}

int main()
{
    int n;
    printf("Enter the value of n of n'th fibonachhi sequence: ");
    scanf("%d", &n);
    if(n==0){
        printf("0");
    }else if (n==1){
        printf("0 1");
    }else{
        printf("0 1 ");
        get_fibo_seq(n-1);
    }
    printf("\n");
    cout<< "fibonacchi number: "<< get_fibo(0, 1, n)<< endl;
    printf("\n");

    if(n==0){
        printf("0");
    }else if (n==1){
        printf("0 1");
    }else{
        printf("0 1 ");
        get_fibo_seq2(n);
    }
    printf("\n");
    get_fibo_seq3(n-1);
    printf("\n");

    printf("nth(%d) fibo: %d\n", n, get_fibo_seq4(n));
    return 0;
}
