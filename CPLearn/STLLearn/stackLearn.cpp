#include <iostream>
#include <stack>
using namespace std;
void printStack(stack <int> ss)
{
    stack <int> sg = ss;
    while (!sg.empty())
    {
        cout << '\t' << sg.top();
        sg.pop();
    }
    cout << '\n';
}

int main ()
{
    stack <int> newst;
    newst.push(55);
    newst.push(44);
    newst.push(33);
    newst.push(22);
    newst.push(11);
    newst.emplace(11);
    newst.emplace(45);
    newst.emplace(50);

    cout << "The stack newst is : ";
    printStack(newst);
    cout<< "Is empty: ";
    (newst.empty())? cout<< "true"<< endl:cout<< "false"<< endl;
    cout << "newst.size() : " << newst.size()<< endl;
    cout << "newst.top() : " << newst.top()<< endl;
    cout << "newst.pop() : " << endl;
    newst.pop();
    printStack(newst);
    return 0;
}
