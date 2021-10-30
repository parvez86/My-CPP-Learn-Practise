#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void add_item(int val, vector<int>& arr, int max_indx)
{
    int indx = 0;
    while(arr[indx] != -1 && arr[indx] != '\0' && arr[indx]<= val){
        indx++;
    }
    int j=max_indx;
    while(j>=indx){
        arr[j] = arr[j-1];
        j--;
    }
    arr[indx] = val;
    return ;
}

int find_nth(vector<int> vec, int nth)
{
    int len = vec.size();
    vector<int> sort_vec(len, -1);
    for(int i=0; i<len; i++){
        add_item(vec[i], sort_vec, i);
    }
    return (nth<=len)?sort_vec[nth-1]:-1;
}

int find_nth2(vector<int> vec, int nth)
{
    sort(vec.begin(), vec.end());
    return (nth<=vec.size())?vec[nth-1]:-1;
}

int find_nth3(vector<int> vec, int nth)
{
    multiset<int> st(vec.begin(), vec.end());
    return *next(st.begin(), nth-1);
}

int main()
{
    vector<int> vec{1, 2, 9, 8, 3, 4, 7, 6, 5, 1};
    int nth_val = 6;
    cout<< "Nth item is: "<< find_nth(vec, 6)<< endl;
    cout<< "Nth item is: "<< find_nth2(vec, 6)<< endl;
    cout<< "Nth item is: "<< find_nth3(vec, 6)<< endl;
    return 0;
}
