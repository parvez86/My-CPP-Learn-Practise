#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        cout<< vec[i]<< " ";
    }
    cout<< endl;
}
// need lower bound
int b_search(vector<int> vec, int low, int high, int data, int len)
{
    if(low>high) return len;
    int mid = low+(high-low)*.5;
    if(mid>=0 && mid<len && vec[mid]==data) return mid;
    if(vec[mid]>data) return b_search(vec, low, mid-1, data, len);
    else return b_search(vec, mid+1, high, data, len);

}

int b_search2(vector<int> vec, int p)
{
    int low=0, high = vec.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;

        if(vec[mid] == p) return mid;
        else if(vec[mid]>p) high = mid-1;
        else low=mid+1;
    }
    return vec.size();
}

void addItem(vector<int>& vec, int p)
{
    int indx;
    if(vec.size()==0){
        vec.push_back(p);
        return;
    }else if(vec.size()==1){
        vec.push_back(p);
        if(vec[0]>vec[1]){
            int temp = vec[0];
            vec[0] = vec[1];
            vec[1] =temp;
        }
        return;
    }
   // indx = b_search(vec, 0, vec.size()-1, p, vec.size());
    indx = b_search2(vec, p);
    cout<< indx<< endl;
    if(indx==vec.size()){vec.push_back(p); return;}
    vec.push_back(0);
    for(int i=vec.size()-1; i>indx; i--) vec[i] = vec[i-1];
    vec[indx] = p;
    print_vec(vec);
    return;
}

int main()
{
    int a[] = {2, 3, 1, 4, 5, 6, 9};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> vec;

    for(int i=0; i<n; i++){
        addItem(vec, a[i]);
    }
    print_vec(vec);
    return 0;
}
