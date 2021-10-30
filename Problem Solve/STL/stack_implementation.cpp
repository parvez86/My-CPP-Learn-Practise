#include <iostream>
#include <vector>
#define MX 100

using namespace std;
vector<int> V(MX, 0);
int top, max_len=MX;

void init_stack(int n)
{
    top = -1;
    max_len = n;
    for(int i=0; i<n; i++) V[i] = 0;
    return;
}

void push(int val)
{
    if(top<max_len-1){
        V[++top] = val;
    }else{
        cout<< "Stack overflow"<< endl;
    }
}

void pop()
{
    if(top>=0){
        top--;
    }
    else{
        cout<< "Stack is empty!"<< endl;
    }
}

int peek()
{
    if(top==-1) return -1;
    return V[top];
}

void display()
{
    if(top!=1){
        for(int i=0; i<=top; i++){
            cout<< "index ["<< i<<"]: "<< V[i]<<endl;
        }
        cout<< "top: "<< top<< endl;
    }else{
        cout<< "Stack is empty"<< endl;
    }
}

int main()
{
    int n;
    bool isQuit = false;
    cout<< "Enter the size of stack: ";
    cin>> n;
    // initialize stack
    init_stack(n);

    string txt = "Enter the option: \n"
    "1 -> push() \n2 -> pop() \n3 -> top() \n4 -> display() \n5 -> exit()\n";
    while(!isQuit){
        int opt;
        cout<< txt;
        cin>> opt;
        switch(opt){
        case 1:
            int val;
            cout<< "Enter the value: ";
            cin>>val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            val = peek();
            (val==-1)?cout<< "Stack is empty!":cout<< "top() = "<< val<< endl;
            break;
        case 4:
            display();
            break;
        case 5:
            isQuit = true;
            break;
        default:
            break;
        }
    }
    return 0;
}
/*

5
1 5 2 4 3





*/
