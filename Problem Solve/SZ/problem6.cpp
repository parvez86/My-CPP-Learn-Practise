#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>>  vec;

void print_spiral(int n)
{
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cout<< vec[i][j]<< "\t";
        }
        cout<< endl;
    }

}

void get_spiral(int n)
{
    // max loop, k = 2*n -1;
    // cnt: 1 to n*n
    int cnt = 1, k=n+n-1;

    //
    for(int p=k; p>0; p--){
        // indices
        int i=0,j=0;

        // if even row from bottom
        // cnt value is incremented to top-bottom diagonal
        if((k-p)%2==0){

            // After 1st n-1 iteration: initial i=0, initial j=n-p;
            if(p<=n){
                i=0;
                j=n-p;
            }
            // for 1st n-1 iteration: initial i = n+ (k+1-p); j=0;
            else{
                i=n-(k+1-p);j=0;
            }
            // fill value to top-bottom diagonal
            while(i<n && j<n) {vec[i++][j++]=cnt++;}
        }else{
            // After 1st n-1 iteration: initial i=p-1, initial j=n-1;
            if(p<=n){
                i=p-1;j=n-1;
            }
            // for 1st n-1 iteration: initial i = n-1; j=k-p;
            else{
                i=n-1;j=k-p;
            }
            // fill value to bottom-top backwards diagonal
            while(i>=0 && j>=0) {vec[i--][j--]=cnt++;}
        }
    }
    return;
}

int main()
{
    int n;
    cin>> n;
    vec.assign(n, vector<int>(n, 0));
    get_spiral(n);
    print_spiral(n);
    return 0;
}
