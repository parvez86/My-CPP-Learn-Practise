#include <iostream>
using namespace std;
class A{
    public:

        // partial virtual function
        virtual void display(){
            cout << "Base class is invoked" << endl;
        }

        /* pure virtual function: pure virtual function
         has no implementation in base class
         */
         virtual void fun() = 0;    // declaration of pure virtual function
};

class B:public A
{
    public:
        void display() {
            cout << "Derived Class is invoked"<<endl;
        }
        void fun() {
            cout << "Hi, this is for fun (pure virtual function)!" << endl;
        }
};

int main()
{
    A* a;    //pointer of base class
    B b;     //object of derived class
    a = &b;
    a->display();   //Late Binding occurs
    a->fun();
}
