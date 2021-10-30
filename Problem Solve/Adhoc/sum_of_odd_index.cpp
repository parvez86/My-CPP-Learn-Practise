#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int len = arr.size();
        for(int i=0; i<len; i++){
            int sub_result = 0;
            int countOdd = 0;
            for(int j=i; j<len; j++){
                sub_result += arr[j];
                countOdd ++;
                if(countOdd % 2== 1) sum += sub_result;
            }
        }
        return sum;
    }
    int sumOddLengthSubarrays2(vector<int>& arr) {
        int len = arr.size(), result = 0;
        for(int i=0; i < len; i++){
            result += ((len-i)*(i+1)+1)/2 * arr[i];
        }
        return result;
    }
};


int main()
{
    Solution ob;
    vector<int> vec{10, 11, 12};
    cout<< ob.sumOddLengthSubarrays(vec)<< endl;
    return 0;
}

