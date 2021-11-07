#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x1, int y1) { x = x1; y = y1; }

	/*
    Copy constructor:
        A member function which initializes an object
        using another object of the same class

    Use: The compiler created copy constructor works fine in general.
    We need to define our own copy constructor only if an object has
    pointers or any runtime allocation of the resource like file handle,
    a network connection..etc
    */
	Point(const Point &p1) {x = p1.x; y = p1.y; }

	int getX()		 { return x; }
	int getY()		 { return y; }
};

int main()
{
    Point p1(10, 15); // Normal constructor is called here
	Point p2 = p1; // Copy constructor is called here

	// Let us access values assigned by constructors
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
	cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

	return 0;
}
