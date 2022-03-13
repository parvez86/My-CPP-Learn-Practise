#include <iostream>
#include <vector>
using namespace std;

// naive

void rev_array(int arr[], int len)
{
    for(int i=0; i<len/2; i++){
        int temp = arr[len-i];
        arr[len-i] = arr[i];
        arr[i] = temp;
    }
    // print
    cout<< "The items are: "<< endl;
    for(int i=0; i<=len; i++){
        cout<<arr[i]<< " ";
    }
    cout<< endl;
}

// naive with vector
void rev_array2(vector<int> vec)
{
    int len = vec.size()-1;
    for(int i=0; i<len/2; i++){
        int temp = vec[len-i];
        vec[len-i] = vec[i];
        vec[i] = temp;
    }
    cout<< "The items are: "<< endl;
    for(int i=0; i<=len; i++) cout<< vec[i]<< " ";
    cout<< endl;
}

// using recursion
void rev_array3(vector<int>& vec, int indx)
{
    if(indx==vec.size()/2) return;
    int temp = vec[indx];
    vec[indx] = vec[vec.size()-1-indx];
    vec[vec.size()-1-indx] = temp;
    rev_array3(vec, indx+1);
}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr_vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    rev_array(arr, (int)sizeof(arr)/sizeof(arr[0])-1);
    rev_array2(arr_vec);
    rev_array3(arr_vec, 0);
    for(int i=0; i<arr_vec.size(); i++){
        cout<< arr_vec[i]<< " ";
    }
    cout<< endl;
    return 0;
}
