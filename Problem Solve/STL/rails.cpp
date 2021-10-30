#include <iostream>
#include <stack>

using namespace std;
stack<int> st;
void marshal(int n)
{

    while(true){
        int val, top=0;
        while(!st.empty()) st.pop();
        for(int i=n; i>0; i--){
            cin>> val;
            if(val==0) return;
            while(top<val){
                top++;
                st.push(top);
            }
            if(st.top()==val) st.pop();
        }
        (st.empty())? cout<< "Yes":cout<< "No";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t, flag=-1;
    stack<int> st;
    while(cin>> t && t!=0){
        marshal(t);
        cout<< endl;
    }
    return 0;
}

