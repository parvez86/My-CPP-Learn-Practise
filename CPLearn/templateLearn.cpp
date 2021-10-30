#include <iostream>
using namespace std;

/* function template */
template<class T> T add(T &a,T &b)
{
    T result = a+b;
    return result;
}

// with single-parameter
template<class X> void fun(X a)
{
    std::cout << "Value of a is : " <<a<< std::endl;
}

// template overloading
template<class X,class Y> void fun(X a,Y b)
{
    std::cout << "Value of a is : " <<a<< std::endl;
    std::cout << "Value of b is : " <<b<< std::endl;
}

/* function template*/

/* class template*/
template<class T>
class A
{
    public:
        T num1 = 5;
        T num2 = 6;
        void add()
        {
            std::cout << "Addition of num1 and num2 : " << num1+num2<<std::endl;
        }
};

// with multi-parameters
template<class T1, class T2>
class B
{
    T1 a;
    T2 b;
    public:
        B(T1 x,T2 y)
        {
            a = x;
            b = y;
        }
        void display()
        {
            std::cout << "Values of a and b are : " << a<<", "<<b<<std::endl;
        }
};

template < class T, int size>
class C
{
    public:
        T arr[size];
        void insert(){
            for(int i=0; i<size; i++) arr[i] = i;
        }

        void display(){
            cout<< "The indices are: ";
            for(int i=0; i<size; i++) cout<< arr[i]<< " ";
            cout << endl;
        }
};


/* class template*/
int main()
{
    int i =2;
    int j =3;
    float m = 2.3;
    float n = 1.2;
    cout<<"Addition of i and j is :"<<add(i,j)<< endl;
    cout<<"Addition of m and n is :"<<add(m,n)<< endl;
    fun(10);
    fun(20,30.5);

    // use of class template
    A <int> a;
    a.add();

    B <int,float> b(5, 7.3);
    b.display();


    // use of none type templates
    C <int, 10> c;
    c.insert();
    c.display();
    return 0;
}
