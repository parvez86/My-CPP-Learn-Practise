#include <iostream>

using namespace std;

int main () {
   int    i; // Declare variable I as int
   double d; // Declare variable d as double type

   // declare reference variables for I and d
   int&    r = i;// r is reference to i
   double& s = d;// s is reference to d

   i = 5;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;

   d = 11.7;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;

   return 0;
}
