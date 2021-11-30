#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    void deleteNode(ListNode* node) {

        // head or tail node need not delete
        // for list: 1-> 2-> 3-> 4
        // node 2
        // 1. make next node value to current node value
        // 2. make next node's next as current node's next

        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }

    void displayList(ListNode* head){
        if(head == NULL) return;
        cout<< head->val<< " ";
        displayList(head->next);
    }
};

int main()
{
    Solution obj;
    int head[] = {1,2,3,4};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    obj.deleteNode(root->next->next);
    obj.displayList(root);
    return 0;
}


/*
// sample test cases
head = [1,2,3,4]
head = [0,1]
head = [-3,5,-99]
*/
