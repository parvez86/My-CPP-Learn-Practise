#include <bits/stdc++.h>

using namespace std;
void print_vec(vector<int> vec);

void min_heapify(vector<int>& vec, int i, int n)
{

    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    // if left child is larger than root
    if(l<n && vec[l]>vec[largest]){
        largest = l;
    }

    // if right child is larger than root
    if(r<n && vec[r]>vec[largest]){
        largest = r;
    }

    // if largest is not root
    // swap the root & child
    // recursively
    if(largest != i){
        swap(vec[i], vec[largest]);

        // min_heapify the affected sub-tree
        min_heapify(vec, largest, i);
    }
}

void heap_sort_min(vector<int> vec)
{
    // build heap
    for(int i = vec.size()/2; i>=0; i--){
        min_heapify(vec, i, vec.size()-1); // min_heapify(arr, item, root)
    }

    // extract one by one
    for(int i=vec.size()-1; i>0; i--){
        swap(vec[0], vec[i]);

        // call min_heapify
        min_heapify(vec, 0, i);
    }
    print_vec(vec);
}

void max_heapify(vector<int>& vec, int i, int n)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;


    // if left child is smaller than root
    if(l<n && vec[l] < vec[largest]){
        largest = l;
    }

    // if right child is smaller than root
    if(r<n && vec[r] < vec[largest]){
        largest = r;
    }

    // if largest is not root
    // swap the root & child
    // recursively
    if(largest != i){
        swap(vec[i], vec[largest]);

        // max_heapify the affected sub-tree
        max_heapify(vec, largest, i);
    }
}

void heap_sort_max(vector<int> vec)
{
    // build heap
    for(int i = vec.size()/2; i>=0; i--){
        max_heapify(vec, i, vec.size()-1); // max_heapify(arr, item, root)
    }

    // extract one by one
    for(int i=vec.size()-1; i>0; i--){
        swap(vec[0], vec[i]);

        // call max_heapify
        max_heapify(vec, 0, i);
    }
    print_vec(vec);
}

void print_vec(vector<int> vec)
{
    cout<< "The items of tree: ";
    for(const auto it:vec) cout<< it<< " ";
    cout<< endl;
}

// time complexity=O(nlogn) (all cases), space complexity= O(1)
int main()
{
    vector<int> vec {12, 11, 13, 5, 6, 7};
    // ascending order -> min-heap
    heap_sort_min(vec);
    // descending order -> max-heap
    heap_sort_max(vec);
    return 0;
}
