#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> st)
{
    cout<< "The items of set are: ";
    for(const auto it:st){
        cout<< it<< " ";
    }
    cout<< endl;
}
int main(void)
{
    set<int> m = {100,200,300, 350, 400};
    printSet(m);
    // auto it = m.find(300);
    /*
        functions:
            empty, size, max_size, insert, emplace, erase, swap, clear, emplace, find, count,
            lower_bound, upper_bound, equal_range(returns (lower_bound, upper_bound))
    */
    cout<< "empty (bool): "<< m.empty()<< endl;
    cout<< "size: "<< m.size()<< endl;
    cout<< "max size: "<< m.max_size()<< endl;
    cout << "find (300) : " << *m.find(300) << endl;
    cout<< "lower bound (301): "<< *m.lower_bound(301)<< endl;
    cout<< "Upper bound (302): "<< *m.upper_bound(320)<< endl;

    m.insert(250);
    cout<< "After inserting 250: "<< endl;
    printSet(m);

    m.erase(300);
    cout<< "After erasing 300: "<< endl;
    printSet(m);

    m.clear();
    cout<< "After clear(): "<< endl;
    printSet(m);
    return 0;
}
