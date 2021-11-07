#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    /*
        functions:
            flip, any. count, none, operator[], reset,
            set, size, test, to_string, to_ullong, to_ulong()()
    */

    bitset<4> b(string("0101"));
    cout<< "data: "<< b<< endl;
    cout<< "Size: "<< b.size()<< endl;
    cout<< "flip (no arg): "<< b.flip()<< endl;
    // from right to left
    cout<< "flip (at index 3): "<< b.flip(3)<< endl;

    // it counts 1
    cout<< "count: "<< b.count()<< endl;
    cout<< "Is all (bool): "<< b.all()<< endl;
    cout<< "Is any (bool): "<< b.any()<< endl;
    cout<< "Is none (bool): "<< b.none()<< endl;
    // check if bit is 1 at specific position
    cout<< "Test (bool): "<< b.test(3)<< endl;
    cout<< "Reset: "<< b.reset()<< endl;
    cout<< "Set: "<< b.set()<< endl;
    cout<< "To string: "<< b.to_string()<< endl;
    cout<< "To ulong: "<< b.to_ulong()<< endl;
    cout<< "To ullong: "<< b.to_ullong()<< endl;

    //cout<<b.f();
    return 0;
}
