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
    void add_nodes(ListNode* curr, ListNode*& node)
    {
        if(!curr) return;
        ListNode* new_node = new ListNode(curr->val);
        node->next = new_node;
        node = node->next;
        if(!curr->next) return;
        add_nodes(curr->next->next, node);
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* new_head = new ListNode;

        ListNode* curr = new_head;
        if(!head || !head->next) return head;
        // add odd indexed nodes
        add_nodes(head, curr);

        // add even indexed nodes
        add_nodes(head->next, curr);
        return new_head->next;
    }
    void displayList(ListNode* head){
        if(head == NULL) {cout<<endl;return;}
        cout<< head->val<< " ";
        displayList(head->next);
    }
};


int main()
{
    Solution obj;
    ListNode* root;
    int head[] = {2,1,3,5,6,4,7};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.oddEvenList(root);
    obj.displayList(root);

    return 0;
}



/*
Test cases
Input: head = [1,2,3,2,3,4,4,5]
Output: [1,2,5]

Input: head = [1,2,1,3,1]
Output: [2,3]
*/


