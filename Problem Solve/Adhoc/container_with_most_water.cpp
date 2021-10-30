#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int indx1=0,len = height.size();
        int indx2=len-1;

        int maxArr = min(height[indx1], height[indx2]) * abs(indx1-indx2);

        while(indx1<indx2){
            maxArr = max(maxArr, min(height[indx1], height[indx2]) * abs(indx1-indx2));
            (height[indx1]<height[indx2])? indx1++:indx2--;
        }
        return maxArr;
    }
};


int main()
{
    Solution ob;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout<< ob.maxArea(height)<< endl;
    return 0;
}
