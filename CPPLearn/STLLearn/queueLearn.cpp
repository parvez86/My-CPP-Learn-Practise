#include <iostream>
#include <queue>
using namespace std;
void printQueue(queue <int> sg)
{
    queue <int> ss = sg;
    while (!ss.empty())
    {
        cout << '\t' << ss.front();
        ss.pop();
    }
    cout << '\n';
}

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "The queue q is : ";
    printQueue(q);

    cout << "\nq.size() : " << q.size();
    cout << "\nq.front() : " << q.front();
    cout << "\nq.back() : " << q.back();

    cout << "\nq.pop() : ";
    q.pop();
    printQueue(q);

    return 0;
}
