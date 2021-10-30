#include <iostream>
#include <stack>

using namespace std;

void get_result(string exp)
{
    stack<int> st;
    int len = exp.size();
    for(int i=0; i<len; i++){
        // if '+' or '*' operator skip & perform respective operation
        if(exp[i]=='+' || exp[i]=='*'){
            // if '*' are found then immediately perform the operation
            // push the result into the stack
            if(exp[i]=='*' && i+1<len){
                // get the previous val from the stack
                // instead of push the result the product of 2 corresponding value
                int temp=st.top();
                st.pop();
                temp*=(exp[i+1]-'0');
                st.push(temp);
                // skip the next value
                i++;
            }
            continue;
        }
        // store the value into the stack
        st.push(exp[i]-'0');
    }
    int sum = 0;
    // all values are converted into the summation value
    // perform sum
    while(!st.empty()){

        sum+=st.top();
        st.pop();
    }
    cout<< "Output: "<< sum<< endl;
    return;
}
int main()
{
    string s;
    cin>> s;
    get_result(s);
    return 0;
}
