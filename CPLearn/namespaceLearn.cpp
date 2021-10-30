#include <iostream>
using namespace std;

namespace First{
    void sayHello(){
        cout<<"Hello First Namespace"<<endl;
    }
}

namespace Second{
    void sayHello(){
        cout<<"Hello Second Namespace"<<endl;
    }
}

// with the help of 'using' keyword
using namespace First;
int main()
{
    // without the help of using keyword
    First::sayHello();
    Second::sayHello();

    // with the help of using keyword
    sayHello();
    return 0;
}
