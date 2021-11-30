#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* getMid(ListNode* slow_pntr, ListNode* fast_pntr){
        if(!fast_pntr || !fast_pntr->next) return slow_pntr;
        return getMid(slow_pntr->next, fast_pntr->next->next);
    }
public:
    ListNode* middleNode(ListNode* head) {
        // if number node is single then return it
        // else return mid node
        return (!head->next)? head:getMid(head, head);
    }
};

int main()
{
    Solution obj;
    int head[] = {1, 2};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    ListNode* mid = obj.middleNode(root);
    cout<< mid->val<< endl;
    return 0;
}


/* sample test cases
head = [1,2,3,4,5]
head = [1,2,3,4,5,6]

*/
