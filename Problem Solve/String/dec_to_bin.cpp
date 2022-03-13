#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

// using reverse function
void decToBin(int num)
{
    string res="";
    cout<< "The original number is: "<< num<< endl;
    while(num>0){
        int rem = num % 2;
        res += (rem+'0');
        num /= 2;
    }
    reverse(res.begin(), res.end());
    cout<< "The binary form of the number: "<< res<< endl;
    return;
}


// using stack
void decToBin2(int num)
{
    stack<int>st;
    cout<< "The original number is: "<< num<< endl;
    while(num>0) {st.push(num%2); num/=2;}
    cout<< "The binary form of the number: ";
    while(!st.empty()) {cout<< st.top(); st.pop();}
    cout<< endl;
    return;
}


// using bitwise operator
void decToBin3(int num)
{
    cout<< "The original number is: "<< num<< endl;
    cout<< "The binary form of the number: ";
    for(int i=31; i>= 0; i--){
        int k = num>> i;
        cout<< (k&1);
    }
    cout<< endl;
    return;
}

// using recursion
int to_bin(int num)
{
    if(num==1 || num==0) return num;
    return (num%2)+to_bin(num/2)*10;
}

void decToBin4(int num)
{
    int bin_num = to_bin(num);
    cout<< "The original number is: "<< num<< endl;
    cout<< "The binary form of the number: "<< bin_num<< endl;
}

// the decimal number is string
void div_str(string& s, int num)
{
    int len = s.size(), sum=0;
    string res="";
    for(int i=0; i<len; i++){
        sum*=10;
        sum+=(s[i]-'0');
        if(sum>num){
            int div_num = sum/num;
            res.push_back(div_num+'0');
            sum-=(div_num*num);
            continue;
        }
    }
    int len2 = 0;
    while(num>0) {num/=10;len2++;}
    for(int i=res.size(); i<(len-len2); i++) res.push_back('0');
    s = res;
    return;
}

void to_bin2(string &num, string& res)
{
    if(num.size()==0) return;
    int rem = (num[num.size()-1]-'0')%2;
    div_str(num, 2);
    to_bin2(num, res+=(rem+'0'));
}

void decToBin5(string num)
{
    string res= "";
    cout<< "The original number is: "<< num<< endl;
    to_bin2(num, res);
    reverse(res.begin(), res.end());
    cout<< "The binary form of the number: "<< res<< endl;
}

int main()
{
    int num = 53;
    decToBin(num);
    decToBin2(num);
    decToBin3(num);
    decToBin4(num);
    decToBin5("53");
    return 0;
}
