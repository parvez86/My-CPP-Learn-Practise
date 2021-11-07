#include <iostream>
#include <fstream>
using namespace std;

int main () {

    /* for write to file*/
    ofstream filestream("testout.txt");
    if (filestream.is_open())
    {
        filestream << "Welcome to javaTpoint.\n";
        filestream << "C++ Tutorial.\n";
        filestream.close();
    }
    else cout <<"File opening is fail.";


    /* read file*/
    string srg;
    ifstream filestream1("testout.txt");
    if (filestream1.is_open())
    {
        while (getline (filestream1, srg) )
        {
        cout << srg <<endl;
        }
        filestream1.close();
    }
    else {
        cout << "File opening is fail."<<endl;
    }

    return 0;
}
