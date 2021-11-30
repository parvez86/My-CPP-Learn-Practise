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

    void insert_node(ListNode*& head, ListNode* curr, ListNode* prev, ListNode* node, bool flag){
        if(!curr) {
            if(flag) return;
            if (prev) prev->next = node;
            curr = node;
            node->next = NULL;
            flag = true;
        }

        else if(!flag && curr->val >= node->val){
                if (prev) prev->next = node;
                else head = node;
                node->next = curr;
                curr = node;
                flag = true;
                return;
        }
        insert_node(head, curr->next, curr, node, flag);
        return;
    }

    ListNode* insert_node2(ListNode* curr, ListNode* prev, ListNode* node, bool flag){
        if(!curr) {
            if(flag) return curr;
            if (prev) prev->next = node;
            curr = node;
            flag = true;
            node->next = NULL;
        }

        else if(!flag && curr->val >= node->val){
                if (prev) prev->next = node;
                node->next = curr;
                curr = node;
                flag = true;
        }
        curr->next = insert_node2(curr->next, curr, node, flag);
        return curr;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head && !head->next) return head;
        ListNode* curr = head->next;
        head->next = NULL;
        while(curr){
            ListNode* next = curr->next;
            insert_node(head, head, NULL, curr, false);

            displayList(head);
            curr = next;
        }
        return head;
    }

    ListNode* insertionSortList2(ListNode* head) {
        if(!head && !head->next) return head;
        ListNode* curr = head->next;
        head->next = NULL;
        while(curr){
            ListNode* next = curr->next;
            head = insert_node2(head, NULL, curr, false);
            curr = next;
        }
        return head;
    }

    void displayList(ListNode* head){
        if(head == NULL) {cout<< endl; return;}
        cout<< head->val<< " ";
        displayList(head->next);
    }
};

int main()
{
    Solution obj;
    int head[] = {4, 2, 1, 3};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.insertionSortList(root);
    obj.displayList(root);
    return 0;
}

