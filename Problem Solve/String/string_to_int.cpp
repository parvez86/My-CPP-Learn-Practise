#include <iostream>
#include <string>
#define ll long long

ll result;
using namespace std;


ll int str_to_int(string number)
{
    ll result = 0;
    int indx =-1;
    while(number[++indx] != '\0'){
        result*=10;
        result+=(number[indx]-'0');
    }
    return result;
}

// using recursion
void str_to_int2(string number, int indx, int len){
    if (indx==len) return;
    result *= 10;
    result += (number[indx]-'0');
    str_to_int2(number, indx+1, len);
}

ll str_to_int3(string number, int len){
    if(len== 0) return number[0]-'0';
    int result = str_to_int3(number, len-1)*10 + (number[len]-'0');
    // return result*10 + (number[len]-'0');
    return result;
}

// using string function
// only for int
ll str_to_int4(string number)
{
    return stoi(number);
}

int main()
{
    // string number = "18929182191";
    string number = "18929182";
    cout<< "Equivalent number: "<< str_to_int(number)<< endl;
    str_to_int2(number, 0, number.size());
    cout<< "Equivalent number (using recursion): "<< result<< endl;
    result = 0;
    cout<< "Equivalent number (using recursion): "<< str_to_int3(number, number.size()-1)<< endl;
    cout<< "Equivalent number (stoi()): "<< str_to_int4(number)<< endl;
}
