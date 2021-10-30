#include <iostream>
using namespace std;
class A
{
    public:
    void display()
    {
        cout << "Class A" << endl;
    }
};
class B
{
    public:
    void display()
    {
        cout << "Class B" << endl;
    }
};

class C : public A, public B
{
public:
    // this causes ambiguity (diamond pattern problem)
   /* void view()
    {
        display();
    }*/

    // fix ambiguity

    void view()
    {
        A::display();
        B::display();
    }
};
int main()
{
    C c;

    // it causes ambiguity
   // c.display();

    // fix ambiguty
    //c.A::display();
    c.view();
    return 0;
}
