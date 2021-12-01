#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

using namespace std;

void print_item(int p) {
    cout<< p<< " ";
}

void print_odd(int p) {
    if(p%2) cout<< p<< " ";
}

void print_even(int p) {
    if(!(p%2)) cout<< p<< " ";
}

bool myfunction (int i,int j) {return (i>j);}

int main()
{
    array<int, 6> arr= {25,27,29,31,33,36};
    //vector<int> arr{25,27,29,31,33,36};
    all_of(arr.begin(), arr.end(), [](int k) {return k%2;})?
        cout <<"All the array elements are odd."<< endl:
            cout<< "All the array elements are not odd"<< endl;

    any_of(arr.begin(), arr.end(), [](int k) {return k%2==0;})?
        cout <<"At least an element is even."<< endl:
            cout<< "All the array elements are odd"<< endl;

    none_of(arr.begin(), arr.end(), [](int k) {return k%2==0;})?
        cout <<"All the array elements are odd."<< endl:
            cout<< "All the array elements are not odd"<< endl;

    cout<< "Array item: ";
    for_each(arr.begin(), arr.end(), print_item);
    cout<< endl;

    cout<< "odd item: ";
    for_each(arr.begin(), arr.end(), print_odd);
    cout<< endl;

    cout<< "even item: ";
    for_each(arr.begin(), arr.end(), print_even);
    cout<< endl;

    // permutation
    array <int, 6> arr2= {25,31,33,27,29,36};
    is_permutation(arr.begin(), arr.end(), arr2.begin())?
        cout<< "The 2 array is same."<< endl:
            cout<< "The 2 array is not same."<< endl;

    string elem[10] = {"kunal","suraj","shweta","chhavi"};
    //move_backward (elem,elem+4,elem+5);
    cout<< "String items are: "<< endl;
    for(auto it: elem) cout << it<< " ";
    cout<< endl;

    vector<string> result;

    transform(arr.begin(), arr.end(), back_inserter(result),
        [](int x) { return to_string(x * 2); });

    for_each(result.begin(), result.end(),
        [](const string& s) { cout << s << endl; });

    replace(result.begin(), result.end(), "66", "65");
    for_each(result.begin(), result.end(),
        [](const string& s) { cout << s << endl; });

    vector<int> v = { 2,5,3,3,1,2,4,2,1,1,4,4,3,3,3};
    sort(v.begin(), v.end());
    for(const auto &p:v) cout<< p<< " ";
    cout<< endl;

    // reverse sort
    //sort(v.begin(), v.end(), [](int i,int j) { return (i>j); });
    sort(v.begin(), v.end(), greater<int>());
    for(const auto &p:v) cout<< p<< " ";
    cout<< endl;
    // blind unique detection.
    // array must be sorted.
    auto uni = unique(v.begin(), v.end());
    v.erase(uni, v.end());
    cout<< "Unique: ";
    for_each(v.begin(), v.end(),
        [](const int& s) { cout << s << " "; });
    cout<< endl;
    cout<< "Rotate: ";
    auto pivot = find(v.begin(), v.end(), 2);


    rotate(v.begin(), pivot, v.end());
    for(const auto &p:v) cout<< p<< " ";
    cout<< endl;

    // partial: sort + corresponding_rev_sort
    partial_sort(v.begin(), v.begin()+3, v.end());
    for(const auto &p:v) cout<< p<< " ";
    cout<< endl;

    vector<int> v1 = { 3, 9, 1, 4, 2, 5, 9 };

    auto result1 = minmax_element(v1.begin(), v1.end());
    cout<< "Min: "<< *result1.first << "\tMax: "<< *result1.second<< endl;
    cout << "min element at: " << (result1.first - v1.begin()) << '\n';
    cout << "max element at: " << (result1.second - v1.begin()) << '\n';
    return 0;
}
