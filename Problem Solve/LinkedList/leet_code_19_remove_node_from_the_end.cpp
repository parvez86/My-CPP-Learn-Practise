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
    int count_nodes(ListNode* head, int cnt){
        if(!head) return cnt;
        return count_nodes(head->next, cnt+1);
    }

    ListNode* remove_node(ListNode* curr, int m){
        if(!curr) return NULL;
        if(m==0){
            if(!curr->next) return NULL;
            curr->val = curr->next->val;
            curr->next = curr->next->next;
        }
        curr->next = remove_node(curr->next, m-1);
        return curr;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        if(len==0) return head;
        if(len==n) return head->next;
        curr = head;
        len -= n;

        while(len>1){
            curr=curr->next;
            len--;
        }
        if(curr && curr->next) {
            curr->next = curr->next->next;
        }
        return head;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        int len = count_nodes(head, 0);
        if(len==0) return head;
        if(n<=len) head = remove_node(head, len-n);
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
    int head[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.removeNthFromEnd(root, 1);
    obj.displayList(root);
    return 0;
}


/*
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]
*/
