#include <iostream>

using namespace std;

// final result
string result="";

// add a single production with the result
void add_mult(string str, int cnt)
{
    // store the result
    // & sum of the production & the result
    string temp_result = "";

    //each time the new production should be multiplied by 10
    // cnt-> count the number of times (for n+1'th rightmost digits)
    //    1 2 3
    //    * 1 2
    //    ------
    //    2 4 6
    //  1 2 3 0  (multiplied by 10)
    // ---------
    //  1 4 7 6
    while(cnt--){
        str.push_back('0');
    }


    int len1=result.size(), len2=str.size(),len,temp=0,carry=0;

    // if result is has comparatively less number of digit then adjust it with the production
    if(len1<len2){
        for(int i=len1;i<len2;i++){
            temp_result.push_back('0');
        }
    }
    // copy the result to temp_result
    for(int i=0; i<len1;i++) temp_result.push_back(result[i]);


    // perform sum & store it to temp_result
    for(int i=len2-1; i>=0; i--){
        temp = (temp_result[i]-'0')+(str[i]-'0')+carry;
        carry=0;
        if(temp>9) {carry=1;temp-=10;}
        temp_result[i] = (temp+'0');
    }
    // remove previous result
    result="";
    // 1st add the top leftmost/final carry
    if(carry>0) result.push_back(carry+'0');
    // add the sum
    for(int i=0; i<len2; i++){
        result.push_back(temp_result[i]);
    }
   // cout<< str<< "\t"<< temp_result<<"\t"<< result<< endl;
}

// multiply a integer with a digit
string get_multiplication(string str1, char ch)
{
    string str="", res="";
    int len = str1.size(),carry=0;

    // multiplication
    // multiply a digit from right to left of the integer
    for(int i=len-1;i>=0;i--){
        // multiply 2 digits
        int temp = ((str1[i]-'0')*(ch-'0')+carry);
       // cout<< temp<< " ";
        // stores the corresponding produced carry of 2 digits
        // and subtracts the carry value from the production
        carry=0;
        if(temp>9){
            carry=temp/10;
            temp%=10;
        }
        // store the production
        str.push_back(temp+'0');
    }

    // store the final carry if has
    if(carry>0) str.push_back(carry+'0');

    // convert the result from left to right directive (actual order)
    // and return
    for(int i=str.size()-1; i>=0; i--){
        res.push_back(str[i]);
    }
    return res;
}

void multiply(string str1, string str2)
{
    int len1=str1.size(),len2=str2.size(), cnt=0;
    // str1 -> 4 5 6 7
    // str2 ->   1 2 3
    for(int i=len1-1; i>=0; i--){
        // multiply the 1st integer with a digit of second integer
        string temp = get_multiplication(str2, str1[i]);
        // cout<< temp<< endl;

        // add the multiplication into the result
        add_mult(temp, cnt);
        cnt++;
    }
    // print the final result
    cout<< result<< endl;
    return;
}
int main()
{
    string str1, str2;
    cin>> str1>> str2;
    multiply(str1, str2);
    return 0;
}
