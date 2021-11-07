#include <iostream>
using namespace std;
class Student {
   public:
       int id;//data member (also instance variable)
       string name;//data member(also instance variable)

       // default constructor
        Student()
        {
            cout<<"Constructor Invoked"<<endl;
        }


        // overloaded constructor
        Student(int id, string name){
            this->id = id;
            this->name = name;
        }

        // default destructor
        ~Student()
        {
            cout<<"Destructor Invoked"<<endl;
        }

       void insert(int i, string n)
        {
            this->id = i;
            this->name = n;
        }
       void display()
        {
            cout<<id<<"  "<<name<<endl;
        }
};
int main(void) {
    Student s1 = Student(201, "Sonoo"); //creating an object of Student
    Student s2; //creating an object of Student
    //s1.insert(201, "Sonoo");
    s2.insert(202, "Nakul");
    s1.display();
    s2.display();
    return 0;
}
