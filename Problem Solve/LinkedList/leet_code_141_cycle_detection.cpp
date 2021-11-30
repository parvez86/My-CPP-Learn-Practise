
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    bool isCircular(ListNode* head, ListNode* slow_pntr, ListNode* fast_pntr){
        if(slow_pntr && fast_pntr && slow_pntr==fast_pntr) return true;
        if(!slow_pntr || !fast_pntr|| !fast_pntr->next || slow_pntr->next==head ) return false;

        return isCircular(head, slow_pntr->next, fast_pntr->next->next);
    }
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        return isCircular(head, head, head->next);
    }
};


int main()
{
    Solution obj;
    ListNode* root;
    int head[] = {1, 2, 3, 2, 1};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    return 0;
}
