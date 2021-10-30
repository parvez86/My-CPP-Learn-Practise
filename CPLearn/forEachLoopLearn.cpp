#include <iostream>
using namespace std;
int main ()
{
    int arr1 [5] = { 10, 20, 30, 40, 50};
    double darr [5] = { 2.4, 4.5, 1.5, 3.5, 4.0 };

    // use range based for loop
    // pass the references
    for ( const auto &var : arr1 )
    {
        cout << var << " " ;
    }
    cout<< endl;
    // use auto keyword to automatically specify the data type of darr container.
    for ( const auto &var : darr )
    {
        cout << var << " " ;
    }


    return 0;
}
