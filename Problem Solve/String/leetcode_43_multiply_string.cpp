#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        return (num1.size()>= num2.size())?get_mult(num1, num2):get_mult(num2, num1);
    }
    string get_mult(string num1, string num2){
        int len = num2.size();
        string result = "";
        for(int i=0; i<len; i++){
            string sing_mult = get_single_mult(num1, num2[i]);
        }
    }
    string get_single_mult(string num1, char ch)
    {
        string result = "";
        int len = num1.size(), carry=0;
        for(int i=len-1; i>=0; i--){
            int mult = (num1[i]-'0')*(ch-'0');
            if(carry>0){
                mult+=carry;
                carry=0;
            }
            if(mult>9){
                carry = mult/10;
                result += ((mult%10)+'0');
            }
        }
        if(carry>0) result += (carry+'0');
        reverse(result.begin(), result.end());
        return result;
    }

    string add_str(string num1, string num2){
        num2+='0';
        string res ="";
        if(num2.size()>num1.size()){
            int temp = num2.size() - num1.size();
            while(temp>0){
                res+='0';
            }
        }
        res += num1;
        int len = res.size(), len2 = num2.size(), carry=0;
        for(int i=0; i<len; i++){
            int temp = carry + (res[len-i]-'0');
            if(len2-i>=0) temp += (num2[len2-i]-'0');
            if(temp>9){
                carry = 1;
                temp-=10;
            }
            res[len-i] = (temp + '0');
        }
        return (carry>0)?((carry+'0')+res):res;
    }

};

int main()
{
    Solution obj;
    string num1="1234", num2="456";
    cout<< obj.multiply(num1, num2)<< endl;
    return 0;
}
