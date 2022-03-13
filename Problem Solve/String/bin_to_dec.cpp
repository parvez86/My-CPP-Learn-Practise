#include <iostream>
#include <string>


using namespace std;

int to_dec(string num)
{
    int res=0, pow=1;
    int len = num.size();
    for(int i=len-1; i>=0; i--){
        res+=(pow*(num[i]-'0'));
        pow*=2;
    }
    return res;
}

int to_dec2(string num, int indx, int pow, int res)
{
    if(indx==0) return res+(pow*(num[0]-'0'));
    return to_dec2(num, indx-1, pow*2, res+(pow*(num[indx]-'0')));
}

void binTodec(string num)
{
    cout<< "Binary number: "<< num<< endl;
    // int int_num = to_dec(num);
    int int_num = to_dec2(num, num.size()-1, 1, 0);
    cout<< "Equivalent decimal number: "<< int_num<< endl;
}

int main()
{
    string bin = "10100101";
    binTodec(bin);
    return 0;
}

/*string int_to_str(int n)
{
    string s= "";
    while(n/10){
        s += ((n%10)+'0');
        n/=10;
    }
    s += (n + '0');
    reverse(s.begin(), s.end());
    return s;
}

int bin_to_dec(string bin_num, int i=0)
{
    int n = bin_num.length();
    if (i==n-1) return bin_num[i] - '0';
    return ((bin_num[i] - '0') << (n-i-1))  + bin_to_dec(bin_num, i+1);
}
*/
