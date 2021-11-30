#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* next_min(ListNode* curr, ListNode* node){
        if(!curr) return node;
        if(curr->val< node->val) node = curr;
        return next_min(curr->next, node);
    }

    ListNode* get_mid(ListNode* slow_curr, ListNode* fast_curr){
        if(!fast_curr || !fast_curr->next) return slow_curr;
        return get_mid(slow_curr->next, fast_curr->next->next);
    }

    ListNode* merge_list(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(0);
        ListNode* res_list= head;

        while(list1 || list2){
            if(!list2) {res_list->next = new ListNode(list1->val);list1=list1->next;}
            else if(!list1) {res_list->next = new ListNode(list2->val);list2=list2->next;}
            else if(list1->val <= list2->val) {res_list->next = new ListNode(list1->val);list1=list1->next;}
            else {res_list->next = new ListNode(list2->val);list2=list2->next;}
            res_list = res_list->next;
        }
        return head->next;
    }

public:
    // using merge-sort
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = get_mid(head, head);

        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(mid);
        return merge_list(list1, list2);

    }

    ListNode* sortList2(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> pq;

        ListNode* curr = head;
        while(curr){
            pq.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr){
            curr->val = pq.top();
            curr = curr->next;
            pq.pop();
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
    int head[] = {6, 3, 2, 6, 5, 6, 9, 8, 7};
    int len = sizeof(head)/sizeof(head[0]);


    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.sortList(root);
    obj.displayList(root);
    return 0;
}
