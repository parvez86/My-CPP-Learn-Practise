// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

    class Solution{
    void swap(int *a, int *b){
        int temp=*a;
        *a = *b;
        *b = temp;
    }
    void maxHeapify(vector<int>& nums, int indx, int n){
        // root-> indx
        int largest = indx;
        int l = 2*indx+1;
        int r = 2*indx+2;
        
        if(l<n && nums[l]>nums[largest]){
            largest = l;
        }
        if(r<n && nums[r]>nums[largest]){
            largest = r;
        }
        
        if(largest != indx){
            // swap(&nums[indx] && nums[largest]);
            // swap
            int temp=nums[largest];
            nums[largest]=nums[indx];
            nums[indx]=temp;
            
            // goes to the root
            maxHeapify(nums, largest, n);
        }
    }
    void minHeapify(vector<int>& nums, int indx, int n){
        // root-> indx
        int smallest = indx;
        int l = 2*indx+1;
        int r = 2*indx+2;
        
        if(l<n && nums[l]<nums[smallest]){
            smallest = l;
        }
        if(r<n && nums[r]<nums[smallest]){
            smallest = r;
        }
        
        if(smallest != indx){
            // swap(&nums[indx] && nums[largest]);
            // swap
            int temp=nums[smallest];
            nums[smallest]=nums[indx];
            nums[indx]=temp;
            
            // goes to the root
            minHeapify(nums, smallest, n);
        }
    }
public:
    // time complexity: all-> O(nlogn), space: 0(1)
    // ascending order
    void buildMaxHeap(vector<int> nums){
        
        // 1st build heap & heapify: log2(N)[0, N/2]
        for(int i=nums.size()/2-1; i>=0; i--){
            maxHeapify(nums, i, nums.size()-1);
        }
        
        // heapify: [0, N-1]
        for(int i=nums.size()-1; i>=0;i--){
            // swap(&nums[0], &nums[i]);
            
            // store max root value
            // swap
            int temp=nums[0];
            nums[0]=nums[i];
            nums[i]=temp;
            
            maxHeapify(nums, 0, i);
        }
        cout<< "After heap(max) sort the items are: ";
        for(int i=0; i<nums.size(); i++){
            cout<< nums[i]<< " ";
        }
        cout<< endl;
    }
    
    // descending order
    void buildMinHeap(vector<int> nums){
        
        // 1st build heap & heapify: log2(N)[0, N/2]
        for(int i=nums.size()/2-1; i>=0; i--){
            minHeapify(nums, i, nums.size()-1);
        }
        
        // heapify: [0, N-1]
        for(int i=nums.size()-1; i>=0;i--){
            // swap(&nums[0], &nums[i]);
            
            // store min root value
            // swap
            int temp=nums[0];
            nums[0]=nums[i];
            nums[i]=temp;
            
            minHeapify(nums, 0, i);
        }
        cout<< "After heap(min) sort the items are: ";
        for(int i=0; i<nums.size(); i++){
            cout<< nums[i]<< " ";
        }
        cout<< endl;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 7, 9, 3, 6, 5, 4, 8};
    obj.buildMaxHeap(nums);
    obj.buildMinHeap(nums);
    return 0;
}
