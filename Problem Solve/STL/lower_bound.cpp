#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int isLowerBound(vector<int> vec, int val)
{
    int hi=vec.size()-1, low=0;
    int mid;
    while(hi-low>1){
        mid = low+(hi-low)/2;
        if(vec[mid]<val) low=mid+1;
        else hi=mid;
    }
    if(vec[low]>=mid) return low;   // for upper bound no equal
    if(vec[hi]>=mid) return hi;     // for upper bound no equal
    return len-1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int> vec;
    int n,val;
    cin>> n;
    for(int i=0; i<n; i++) {cin>> val;vec.push_back(val);}
    cin>> n;
    while(n--){
        cin>> val;
        // int it = (int)(lower_bound(vec.begin(), vec.end(), val)-vec.begin());
        int it = isLowerBound(vec, val);
        (vec[it]==val)? cout<< "Yes "<< it+1<<endl:cout<< "No "<< it+1<< endl;
    }
    return 0;
}
