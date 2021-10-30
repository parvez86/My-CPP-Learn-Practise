#include <iostream>
using namespace std;

class B;          // forward declaration.
class A
{
    int x;
    public:
    void setdata(int i)
    {
        x=i;
    }

    /* friend function can access the private
    and protected property */
    friend void min(A,B);         // friend function.
};

class B
{
    int y;
    public:
    void setdata(int i)
    {
        y=i;
    }
    friend void min(A,B);                    // friend function
};

void min(A a, B b)
{
    cout << "Min value: ";
    if(a.x<=b.y)
    cout <<  a.x << endl;
    else
    cout << b.y << endl;
}

int main()
{
    A a;
    B b;
    a.setdata(10);
    b.setdata(20);
    min(a,b);
    return 0;
}
