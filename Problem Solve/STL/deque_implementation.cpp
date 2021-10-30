#include <iostream>
#include <vector>
#define MX 100
using namespace std;
vector<int> V(MX, 0);
int front_indx, rear_indx, max_len=MX;

void init_deque(int n)
{
    front_indx = -1;
    rear_indx = 0;
    max_len = n;
    for(int i=0; i<n; i++) V[i] = 0;
    return;
}

bool isEmpty()
{
    return front_indx == -1;
}

bool isFull()
{
    return (front_indx == 0 && rear_indx==max_len-1) || (front_indx-1==rear_indx);
}

void push_front(int val)
{
    if(isFull()){cout<< "Deque overflow"<< endl; return;}
    if(front_indx == -1){front_indx=rear_indx=0;}
    else if(front_indx==0){front_indx = max_len-1;}
    else front_indx-=1;
    V[front_indx] = val;
}

void push_back(int val){
    if(isFull()){cout<< "Deque overflow"<< endl; return;}
    if(front_indx == -1){front_indx = rear_indx=0;}
    else if(rear_indx==max_len-1) {rear_indx=0;}
    else rear_indx +=1;
    V[rear_indx] = val;
}

int back()
{
    if(isEmpty() || rear_indx<0) return -1;
    return V[rear_indx];
}

int front()
{
    if(isEmpty()) return -1;
    return V[front_indx];
}

void delete_front()
{
    if(isEmpty()) {cout<< "Deque is empty"<< endl; return;}

    // deque has only one element
    if (front_indx == rear_indx) {front_indx = rear_indx = -1;}

    else if(front_indx == max_len-1) front_indx=0;
    else front_indx++;
    return;
}

void delete_back()
{
    if(isEmpty()) {cout<< "Deque is empty"<< endl; return;}

    // deque has only one element
    if(front_indx == rear_indx ) { front_indx = rear_indx = -1;}

    else if(rear_indx == 0) rear_indx=max_len-1;
    else rear_indx--;
    return;
}

void display()
{
    if(isEmpty()) {cout<< "Deque is empty"<< endl; return;}
    int i=front_indx;
    cout<< "Deque: ";
    while(true){
        cout<< V[i]<< " ";
        if(i==rear_indx) break;
        if(i==max_len-1) i=-1;
        i++;
    }
    cout<< endl;
}
int main()
{
    int n;
    bool isQuit = false;
    cout<< "Enter the size of deque: ";
    cin>> n;
    // initialize deque
    init_deque(n);

    string txt = "Enter the option: \n"
    "1 -> push_front() \n2 -> push_back() \n3 -> front() \n4 -> back() \n5 -> delete_front() \n6 -> delete_back() \n7 -> display() \n8 -> exit()\n";
    while(!isQuit){
        int opt, val;
        cout<< txt;
        cin>> opt;

        if(opt==1){
            cout<< "Enter the value: ";
            cin>>val;
            push_front(val);
        }else if(opt == 2){
            cout<< "Enter the value: ";
            cin>> val;
            push_back(val);
        }else if(opt == 3){
            val = front();
            (val==-1)?cout<< "Deque is empty"<<endl:cout<< "front() = "<< val<< endl;
        }else if(opt == 4){
            val = back();
            (val==-1)?cout<< "Deque is empty"<<endl:cout<< "back() = "<< val<< endl;
        }else if (opt == 5){
            delete_front();
        }else if (opt == 6){
            delete_back();
        }else if (opt == 7){
            display();
        }else if ( opt == 8){
            cout<< "Exitting..."<< endl;
            isQuit = true;
        }else{
            cout<< "Enter a valid option.."<< endl;
        }
    }
    return 0;
}
/*

5
1 5 2 4 3
*/
