#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct ListNode{
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    ListNode* find_node(ListNode* curr, int val){
        if(!curr || val<1) return NULL;
        if(val==1) return curr;
        return find_node(curr->next, val-1);
    }

    ListNode* reverse_list(ListNode* curr, ListNode* right){
        if(curr->next==right->next) {
                return curr;
        }

        ListNode* prev = reverse_list(curr->next, right);
        curr->next->next = curr;
        curr->next=NULL;

        return prev;
    }
    void merge_list(ListNode* list1, ListNode* list2){
        if(!list1->next){
            list1->next = list2;
            return;
        }
        merge_list(list1->next, list2);
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if the 2 node are same then
        // return the list unchanged
        if (left == right) return head;

        // get left node
        ListNode* left_node = find_node(head, left);
        // get right_node
        ListNode* right_node = find_node(left_node, 1+right-left);

        // store the left & right part of the list
        ListNode* prev = find_node(head, left-1);
        ListNode* next = right_node->next;

        // reverse the list from left to right node (middle part)
        left_node = reverse_list(left_node, right_node);

        // if left list is not null then
        // added the middle list next to it
        // otherwise, make the first node of the middle list as head
        (prev)? prev->next = left_node:head=left_node;

        // if the right list is not null
        // add it to the next of middle list
        if(next) merge_list(left_node, next);
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
    int head[] = {1,2,3,4,5};
    int len = sizeof(head)/sizeof(head[0]);


    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.reverseBetween(root, 2, 3);
    obj.displayList(root);
    return 0;
}

/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Input: head = [5], left = 1, right = 1
Output: [5]

*/

