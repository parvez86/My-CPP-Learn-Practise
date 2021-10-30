#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printQueue(priority_queue<int> ss)
{
    // store largest value at top
    priority_queue <int> pq = ss;
    while (!pq.empty())
    {
        cout << '\t' << pq.top();
        pq.pop();
    }
    cout << '\n';
    return;
}

void printQueueR(priority_queue<int, vector<int>, greater<int>> ss)
{
    // store smallest value at the top
    priority_queue <int, vector<int>, greater<int>> pq = ss;
    while (!pq.empty())
    {
        cout << '\t' << pq.top();
        pq.pop();
    }
    cout << '\n';
    return;
}
int main()
{
   // sort in descending order
   priority_queue<int, vector<int>, greater<int> > p;  // priority queue declaration

   // sort in ascending order
   priority_queue<int> q;  // priority queue declaration
   p.push(1); // inserting element '1' in p.
   p.push(2); // inserting element '2' in p.
   p.push(3); // inserting element '3' in p.
   p.push(4);
  // p.push(3);
   p.emplace(3); // inserting element '4' in p.

   q.push(5); // inserting element '5' in q.
   q.push(6); // inserting element '6' in q.
   q.push(7); // inserting element '7' in q.
   q.push(8); // inserting element '8' in q.
   //p.swap(q);
   cout << "Elements of p ("<< p.size()<< ") are : " << endl;
   printQueueR(p);
   cout << "Elements of q ("<< q.size()<< ") are : " << endl;
   printQueue(q);
    return 0;
}
