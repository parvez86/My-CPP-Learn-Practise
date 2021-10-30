#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;


string int_to_str(long int n)
{
    string str="";
    while( n > 0 ){
        int rem = n%10;
        str.push_back((rem+'0'));
        n/=10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    long int number;
    cin>> number;

    //built-in functions
    // string to_string
    cout<< "Equivalent string number (to_string()): "<< to_string(number)<< endl;
    stringstream ss;
    ss << number;
    cout<< "Equivalent string number (sstream): "<< ss.str()<< endl;
    cout<< "Equivalent string number: "<< int_to_str(number)<< endl;
    return 0;
}

