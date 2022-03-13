#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = students.size();
        sort(seats.begin(), seats.end(), greater<int>());
        sort(students.begin(), students.end(), greater<int>());
        int moves=0;
        for(int i=0; i<n;i++){
            moves += abs(seats[i]-students[i]);
        }
        return moves;
    }
};

int main()
{
    Solution obj;
    vector<int> seats = {12,14,19,19,12};
    vector<int> students = {19,2,17,20,7};
    cout<< obj.minMovesToSeat(seats, students)<< endl;
    return 0;
}

