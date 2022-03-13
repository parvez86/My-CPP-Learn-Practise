#include <bits/stdc++.h>

using namespace std;
class myComp{
public:
     bool operator()(const int a, const int b){
        bitset<32> p(a),q(b);
        return (p.count()==q.count())?a>b:p.count()>q.count();
    }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comp = [](const int a, const int b){bitset<32> m(a), n(b); return (m.count()==n.count())?a<b:m.count()<n.count();};
        // sort(arr.begin(), arr.end(), myComp());
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    vector<int> sortByBits2(vector<int>& arr) {
        priority_queue<int, vector<int>, myComp> pq;
        for(auto it:arr) pq.push(it);

        vector<int>res;
        while(!pq.empty()){res.push_back(pq.top()); pq.pop();}
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> vec{0,1,2,3,4,5,6,7,8};
    vector<int> res2 = obj.sortByBits2(vec);
    for(auto it:res2) cout<< it<< " ";
    cout<< endl;
    vector<int> res = obj.sortByBits(vec);
    for(auto it:res) cout<< it<< " ";
    cout<< endl;
    return 0;
}
