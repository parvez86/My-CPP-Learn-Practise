#include <iostream>
#include<cstring>

using namespace std;
int main()
{
    string name; // variable declaration
    cout << "Enter your name :" << endl;
    cin>>name;
    cout<<"\nHello "<< name<< endl;
    //cin.clear();
    fflush(stdin);

    cout << "Enter your name :" << endl;
    getline(cin, name);
    cout<<"\nHello "<< name<< endl;

    cout << "Enter your name :" << endl;
    getline(cin, name);
    cout<<"\nHello "<< name<< endl;
    return 0;
}

