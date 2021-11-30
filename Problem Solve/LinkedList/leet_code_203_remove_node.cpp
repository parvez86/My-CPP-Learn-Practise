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
    void remove_node(ListNode*& curr, int val){
        if(!curr) return;
        if(curr->val == val){
            if(curr->next) {
                curr->val = curr->next->val;
                curr->next = curr->next->next;
            }else curr = NULL;
            remove_node(curr, val);
        }else remove_node(curr->next, val);
        return;
    }

    ListNode* remove_node2(ListNode* curr, int val){
        if(!curr) return NULL;
        if(curr->val == val){
            if(curr->next) {
                curr->val = curr->next->val;
                curr->next = curr->next->next;
            }else curr = NULL;
            curr = remove_node2(curr, val);
        }else curr->next=remove_node2(curr->next, val);
        return curr;
    }

    ListNode* remove_node3(ListNode* head, int val){
        ListNode* curr = head;
        while(curr){
            if(curr->val == val){
                if(curr->next){
                    curr->val = curr->next->val;
                    curr->next = curr->next->next;
                }else curr = NULL;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        remove_node(head, val);
        return head;
    }

    ListNode* removeElements2(ListNode* head, int val) {
        return remove_node2(head, val);
    }

    ListNode* removeElements3(ListNode* head, int val) {
        return remove_node3(head, val);
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
    int head[] = {1, 2, 3, 4, 3, 2, 1};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.removeElements(root, 1);
    obj.displayList(root);
    root = obj.removeElements2(root, 2);
    obj.displayList(root);
    root = obj.removeElements3(root, 3);
    obj.displayList(root);
    return 0;
}



/*
Test cases
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []


Input: head = [7,7,7,7], val = 7
Output: []
*/
