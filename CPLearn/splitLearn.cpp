#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    char str[100]; // declare the size of string
    cout << " Enter a string: ";
    cin.getline(str, 100); // use getline() function to read a string from input stream

    // 1. using strtok
    char *ptr; // declare a ptr pointer
    ptr = strtok(str, " , "); // use strtok() function to separate string using comma (,) delimiter.
    cout << " \n Split string using strtok() function: " << endl;
    // use while loop to check ptr is not null
    while (ptr != NULL)
    {
        cout << ptr  << endl; // print the string token
        ptr = strtok (NULL, " , ");
    }

    // 2. using getline
    string str2, T;
    getline(cin, str2);
    stringstream X(str2);

    while (getline(X, T, ' ')){
        cout<< T<< endl;
    }

    // 3. custom split function



    return 0;
}
