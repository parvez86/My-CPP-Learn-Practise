/* method overriding & use of virtual function */
#include <iostream>
using namespace std;
class Animal {
    protected:
        string color = "White";
    public:
        virtual void setColor(string color){
            this->color = color;
        }
        virtual string getColor(){
            return this->color;
        }

        /*void eat(){
            cout<<"Eating..."<< endl;
        }*/

        //virtual keyword: used to tell the compiler to perform dynamic linkage
        // or late binding on the function
        // like method overriding in java
        virtual void eat(){
            cout<<"Eating..."<< endl;
        }
};
class Dog: public Animal
{
    public:
        void setColor(string color){
            Animal::setColor(color);
        }

        string getColor(){
            return Animal::getColor();
        }

        void eat(){
            cout<<"Eating bread..."<< endl;
        }
};

class Cat: public Animal
{
    public:
        void setColor(string color){
            Animal::setColor("Black & White");
        }

        string getColor(){
            return Animal::getColor();
        }

        void eat(){
            cout<<"Eating milk..."<< endl;
        }
};

int main(void) {
    Animal *a;
    Dog d = Dog();
    d.setColor("Black");
    Cat c = Cat();
    c.setColor("Black & White");
    d.eat();
    cout<< d.getColor()<< endl;
    c.eat();
    cout<< c.getColor()<< endl;
    a = &d;
    a->eat();
    cout<< a->getColor()<< endl;
    a = &c;
    a->eat();
    cout << a->getColor()<< endl;
    return 0;
}
