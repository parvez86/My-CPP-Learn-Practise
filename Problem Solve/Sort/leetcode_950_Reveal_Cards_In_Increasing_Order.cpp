#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> t_deck(deck.size(), 0);
    //    for(int it:deck) cout<< it<< " ";
    //    cout<< endl;
        queue<int> q;
        for(int i=0; i<deck.size();i++) q.push(i);
        int i=0;
        while(!q.empty()) {
            t_deck[q.front()] = deck[i++];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return t_deck;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {17,13,11,2,3,5,7};
    //vector<int> arr = {17,13,11,2,3,5,7, 6, 8, 9};
    arr = obj.deckRevealedIncreasing(arr);
    for(int it:arr) cout<< it<< " ";
    cout<< endl;
    return 0;
}
