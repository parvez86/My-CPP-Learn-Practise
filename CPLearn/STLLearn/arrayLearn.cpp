#include <iostream>
#include <array>

using namespace std;


void printArr(array<int, 5> arr)
{
    cout<< "The items of array: "<< endl;
    for(const auto it:arr){
        cout<< it<< " ";
    }
    cout<< endl;
}

int main()
{
    /*
        functions:
            empty, size, max_size, at, front, back, data, fill, swap, get
    */
    array<int, 5> arr = {2, 3, 1, 5, 4};
    printArr(arr);

    cout<< "Empty: "<< arr.empty()<< endl;
    cout<< "Size: "<< arr.size()<< endl;
    cout<< "Max-size: "<< arr.max_size()<< endl;
    cout<< "At(2): "<< arr.at(2)<< endl;
    cout<< "front: "<< arr.front()<< endl;
    cout<< "back: "<< arr.back()<< endl;
    cout<< "get: "<< get<2>(arr)<< endl;
    cout<< "data: "<< *arr.data()<< endl;
    arr.fill(5);
    cout<< "After fill(5): "<< endl;
    printArr(arr);
    return 0;
}
