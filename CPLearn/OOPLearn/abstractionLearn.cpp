#include <iostream>
#include<cmath>


using namespace std;


class calcPow{
    private:
        int num, pow;
    public:
        int get_pow(int num, int pow){
            this->num = num;
            this->pow = pow;
            return calc_pow();
        }
        int calc_pow(){
            int result = 1;
            for(int i=0; i<this->pow; i++) result *= this->num;
            return result;
        }
};


int main()
{
    int n = 4;
    int power = 3;
    calcPow pnt;
    // abstraction of header file
    int result = pow(n,power);         // pow(n,power) is the  power function
    cout << "Cube of n is : " << result << endl;
    cout << "Cube of n is : " << pnt.get_pow(n, power)<< endl;  // user-defined
    return 0;
}
