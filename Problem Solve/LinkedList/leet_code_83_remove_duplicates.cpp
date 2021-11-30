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
    void remove_duplicates(ListNode*& head){
        if(!head) return;
        if(head->next && head->val == head->next->val){
            head->val = head->next->val;
            head->next = head->next->next;
            remove_duplicates(head);
        }else{
            remove_duplicates(head->next);
        }
    }

    ListNode* remove_duplicates2(ListNode* head){
        if(!head) return NULL;
        if(head->next && head->val == head->next->val){
            head->val = head->next->val;
            head->next = head->next->next;
            head = remove_duplicates2(head);
        }else head->next = remove_duplicates2(head->next);
        return head;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        // method 1
        //remove_duplicates(head);

        // method 2
        // head = remove_duplicates2(head);
        ListNode* curr = head;
        while(curr){
            if(curr->next && curr->val == curr->next->val){
                curr->val = curr->next->val;
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }
        return head;
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
    int head[] = {1,1,1,2,3,3};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
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
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/
