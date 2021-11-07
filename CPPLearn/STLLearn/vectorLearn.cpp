#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <string> v;

    v.push_back("Hi");
    v.push_back("How");
    v.push_back("are");
    v.push_back("you");
    v.push_back("?");

    // using iterator
    for(vector<string>::iterator itr=v.begin(); itr!=v.end(); itr++) cout<< *itr<< " ";
    cout<< endl;

    v.insert(v.begin()+1, "?");
    //v.swap()
    // using for-each
    for(const auto it:v) cout<< it<< " ";
    cout<< endl;

    // methods
    cout<< v.at(1)<< endl;
    cout<< v.front()<< endl;
    cout<< v.back()<< endl;

    cout<< "Is empty: ";
    (v.empty())? cout<< "true"<< endl:cout<< "false"<< endl;
    cout<< v.size()<< endl;

    v.push_back("garbaze");
    cout<< v.back()<< endl;
    cout<< "Size: "<< v.size()<< endl;
    cout<< "Capacity: "<< v.capacity()<<endl;
    cout<< "Max size: "<< v.max_size()<<endl;

    v.pop_back();
    cout<< v.back()<< endl;

    v.insert(v.begin()+1, "?");
    v.emplace(v.end(), "?");
    for(const auto it:v) cout<< it<< " ";
    cout<< endl;


    v.erase(v.begin()+1);
    for(const auto it:v) cout<< it<< " ";
    cout<< endl;

    cout<< *v.data()<< endl;
    cout<< "After shrink: "<< endl;
    v.shrink_to_fit();
    cout<< "Size: "<< v.size()<< endl;
    cout<< "Capacity: "<< v.capacity()<<endl;
    cout<< "Max size: "<< v.max_size()<<endl;
    return 0;
}
