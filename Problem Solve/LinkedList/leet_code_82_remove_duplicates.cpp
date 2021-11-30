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
    ListNode* remove_nodes(ListNode* head){
        if(!head) return NULL;
        if(head->next && head->val==head->next->val){
            ListNode* temp = head;
            head = head->next;
            while(head && temp->val == head->val) head = head->next;
            head = remove_nodes(head);
        }else head->next = remove_nodes(head->next);
        return head;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        head = remove_nodes(head);
        return head;
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
    int head[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.deleteDuplicates(root);
    obj.displayList(root);

    return 0;
}



/*
Test cases
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]
*/
