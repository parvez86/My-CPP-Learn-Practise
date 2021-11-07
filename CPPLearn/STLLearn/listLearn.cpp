#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> li;
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.push_front(2);
    li.push_front(3);
    li.push_front(1);
    li.push_back(1);
    li.push_back(2);


    for(const auto it:li) cout<< it<< " ";
    cout<< endl;

    std::cout << "is empty : ";
    (li.empty())? cout<< "true": cout<< "false";
    cout<< endl;
    cout<< "Size: "<< li.size()<< endl;
    cout<< "Max-size: "<< li.max_size()<< endl;
    cout<< "First element: "<< li.front()<< endl;
    cout<< "Back element: "<< li.back()<< endl;
    li.sort();
    cout<< "In increasing order: "<< endl;
    for(const auto it:li) cout<< it<< " ";
    cout<< endl;

    li.reverse();
    cout<< "In reverse order: "<< endl;
    for(const auto it:li) cout<< it<< " ";
    cout<< endl;

    li.unique();
    cout<< "Unique elements: "<< endl;
    for(const auto it:li) cout<< it<< " ";
    cout<< endl;
    return 0;
}
