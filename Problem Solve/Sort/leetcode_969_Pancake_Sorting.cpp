#include <bits/stdc++.h>

using namespace std;


class Solution {
    int find_index(vector<int>& arr, int indx, int item){
        if(indx==arr.size()) return -1;
        if(arr[indx]==item) return indx+1;
        return find_index(arr, indx+1, item);
    }

public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        while(n){
            if(arr[n-1]!=n){
                int k_indx = find_index(arr, 0, n);
                res.push_back(k_indx);

                reverse(arr.begin(), arr.begin()+k_indx);    // get max element at zero index
                reverse(arr.begin(), arr.begin()+n);    // put max element at right index

                res.push_back(n);
            }
            n--;
        }
        return res;
    }

    vector<int> pancakeSort2(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        while(n){
            int k_indx = distance(begin(arr), max_element(arr.begin(), arr.begin()+n));

            if(k_indx+1 != n){
                res.push_back(k_indx+1);

                reverse(arr.begin(), arr.begin()+k_indx+1);    // get max element at zero index
                reverse(arr.begin(), arr.begin()+n);    // put max element at right index

                res.push_back(n);
            }
            n--;
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3,2,4,1};
    vector<int> res = obj.pancakeSort2(arr);
    for(int it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
