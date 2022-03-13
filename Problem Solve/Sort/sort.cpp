#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> vec, string text)
{
    cout<< "The sorted items are("<< text<<"): ";
    for(int i=0; i<vec.size(); i++){
        cout<< vec[i]<< " ";
    }
    cout<< endl;
}

void cswap(int* a, int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void merge_arr(vector<int>& vec, int low, int mid, int high)
{
    int len = high-low+1;
    vector<int> new_vec(len, 0);

    int it1=low, it2=mid+1;

    for(int i=0; i<len; i++){
        (it1==mid+1)?new_vec[i]=vec[it2++]:(it2==high+1)?new_vec[i]=vec[it1++]:
                (vec[it1]<vec[it2])?new_vec[i]=vec[it1++]:new_vec[i]=vec[it2++];
    }

    for(int i=0; i<len; i++) vec[low+i] = new_vec[i];
}

void merge_sort(vector<int>& vec, int low, int high)
{
    if(low>=high) return;

    int mid = low+(high-low)/2;

    //
    merge_sort(vec, low, mid);
    merge_sort(vec, mid+1, high);

    //
    merge_arr(vec, low, mid, high);
}


// Complexity (best, avg, worst):
//  time -> (nlogn)	(nlogn)	(nlogn)
// space -> O(n)
void get_merge_sort(vector<int> vec)
{
    merge_sort(vec, 0, vec.size()-1);
    print_vec(vec, "merge sort");
}

int quick_partition(vector<int>& vec, int low, int high)
{
    int pivot = vec[high];
    int itr = low;

    for(int i=low; i<high; i++){
        if(vec[i] < pivot){
            cswap(&vec[itr++], &vec[i]);
        }
    }
    if(itr != high) swap(vec[high], vec[itr]);
    return itr;

}

void quick_sort(vector<int>& vec, int low, int high)
{
    if(low<high){
        int q_part = quick_partition(vec, low, high);

        quick_sort(vec, low, q_part-1);
        quick_sort(vec, q_part+1, high);
    }
}

// Complexity (best, avg, worst):
//  time -> (nlogn)	(nlogn)	(n^2)
// space -> O(n)
void get_quick_sort(vector<int> vec)
{
    quick_sort(vec, 0, vec.size()-1);
    print_vec(vec, "quick sort");
}

void selection_sort(vector<int>& vec)
{
    for(int i=0; i<vec.size(); i++){
        int min_indx=i, min_val=vec[i];
        for(int j=i+1; j<vec.size(); j++) {
            if(min_val>vec[j]){
                min_val = vec[j];
                min_indx = j;
            }
        }
        if(min_indx != i) cswap(&vec[i], &vec[min_indx]);
    }
}

// Complexity (best, avg, worst):
//  time -> (n^2)	(n^2)	(n^2)
// space -> O(1)
void get_selection_sort(vector<int> vec)
{
    selection_sort(vec);
    print_vec(vec, "selection sort");
}

void insertion_sort(vector<int>& vec)
{
    for(int i=1;i<vec.size(); i++){
        int temp = vec[i];

        int j=i-1;
        while(j>=0 && temp<vec[j]) {vec[j+1] = vec[j];j--;}

        vec[j+1] = temp;
    }
}

// Complexity (best, avg, worst):
//  time -> (n)	(n^2)	(n^2)
// space -> O(1)
void get_insertion_sort(vector<int> vec)
{
    insertion_sort(vec);
    print_vec(vec, "insertion sort");
}


void bubble_sort(vector<int>& vec)
{
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec.size()-i-1; j++){
            if(vec[j]>vec[j+1]){
                cswap(&vec[j], &vec[j+1]);
            }
        }
    }
}
// Complexity (best, avg, worst):
//  time -> (n)	(n^2)	(n^2)
// space -> O(1)
void get_bubble_sort(vector<int> vec)
{
    bubble_sort(vec);
    print_vec(vec, "bubble sort");
}

int main()
{
    vector<int> vec{1, 5, 4, 2, 3, 9, 8, 6, 7};
    get_bubble_sort(vec);
    get_insertion_sort(vec);
    get_selection_sort(vec);
    get_merge_sort(vec);
    get_quick_sort(vec);
    return 0;
}
