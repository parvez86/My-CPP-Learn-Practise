#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>  vec;
int pageSize, pageNumber, skip, order;

void print_vec(int start_indx)
{
    int len=vec.size();
    // also checking index out of bound
    for(int i=start_indx, j=0; i<len && j<pageSize; i++, j++){
        cout<< vec[i]<< " ";
    }
    cout<< endl;
}

int main()
{
    while(true){
        vec.clear();
        int n, val;
        cin>> n;
        for(int i=0; i<n; i++){
            cin>> val;
            vec.push_back(val);
        }
        //cout<< txt<< endl;
        cin>> skip>> pageSize>> pageNumber>> order;

       // skip
        vec.erase(vec.begin(), vec.begin()+skip);

        // order
        // 0 -> ascending
        // 1 -> descending
        if(order==0){
            sort(vec.begin(), vec.end());
        }
        else{
            sort(vec.begin(), vec.end(), greater<int>());
        }

        // print with pageNumber & pageSize
        // initial_index = (pageNumber-1)*pageSize
        // end_index = initial_index+pageSize
        int startIndx = (pageNumber-1)*pageSize;
        print_vec(startIndx);
    }
    return 0;
}
