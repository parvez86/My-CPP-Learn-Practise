#include <iostream>
#include <vector>
#define MX 100
using namespace std;
vector<int> V(MX, 0);
int top, max_len=MX;

void init_queue(int n)
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
        cout<< "Queue overflow"<< endl;
    }
}

void pop()
{
    if(top>=0){
        for(int i=0; i<top; i++) V[i] = V[i+1];
        top--;
    }
    else{
        cout<< "Queue is empty!"<< endl;
    }
}


int back()
{
    if(top==-1) return -1;
    return V[top];
}


int front()
{
    if(top==-1) return -1;
    return V[0];
}


void display()
{
    if(top!=-1){
        for(int i=0; i<=top; i++){
            cout<< "index ["<< i<<"]: "<< V[i]<<endl;
        }
    }else{
        cout<< "Queue is empty"<< endl;
    }
}


int main()
{
    int n;
    bool isQuit = false;
    cout<< "Enter the size of queue: ";
    cin>> n;
    // initialize queue
    init_queue(n);

    string txt = "Enter the option: \n"
    "1 -> push() \n2 -> pop() \n3 -> front() \n4 -> back() \n5 -> display() \n6 -> exit()\n";
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
            val = front();
            (val==-1)? cout<< "Queue is empty!"<<endl:cout<< "front() = "<< val<< endl;
            break;
        case 4:
            val = back();
            (val==-1)?cout<< "Queue is empty!"<<endl:cout<< "back() = "<< val<< endl;
            break;
        case 5:
            display();
            break;
        case 6:
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
