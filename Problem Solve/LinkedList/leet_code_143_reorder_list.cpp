#include <iostream>
#include <queue>
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
    ListNode* get_mid_node(ListNode* slow_curr, ListNode* fast_curr){
        if(!fast_curr || !fast_curr->next) return slow_curr;
        return get_mid_node(slow_curr->next, fast_curr->next->next);
    }
    void get_node_stack(ListNode* curr, stack<ListNode*>& st){
        if(!curr) return;
        st.push(curr);
        get_node_stack(curr->next, st);
    }

    ListNode* get_last(ListNode* curr){
        if(!curr) return NULL;
        if(!curr->next->next) {
            ListNode* temp = curr->next;
            curr->next = NULL;
            return temp;
        }
        return get_last(curr->next);
    }

    ListNode* reverse_list(ListNode* curr){
        if(!curr) return NULL;
        if(!curr->next) return curr;

        ListNode* prev = reverse_list(curr->next);
        curr->next->next = curr;
        curr->next=NULL;

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* mid = get_mid_node(head, head);

        ListNode* curr = head;
        ListNode* temp;

        while(curr != mid && mid->next){
            temp = curr->next;
            curr->next = get_last(mid);
            curr->next->next = temp;
            curr = curr->next->next;
        }
        (curr == mid)? curr->next = NULL:curr->next=mid;
        return;
    }


    void reorderList2(ListNode* head) {
        stack<ListNode* > st;

        ListNode* mid = get_mid_node(head, head);
        get_node_stack(mid, st);

        ListNode* curr = head;
        ListNode* temp;

        while(!st.empty() && curr != mid){
            temp = curr->next;
            ListNode* temp2 = st.top();
            curr->next = temp2;
            curr->next->next = temp;

            st.pop();
            curr = curr->next->next;
        }
        curr->next = NULL;
        return;
    }

    void reorderList3(ListNode* head) {
        ListNode* mid = get_mid_node(head, head);
        mid = reverse_list(mid);

        ListNode* curr = head;
        ListNode* temp;
        ListNode* temp2;

        while(curr != mid && mid){
            temp = curr->next;
            temp2 = mid->next;

            curr->next = mid;
            curr->next->next = temp;

            mid = temp2;
            curr = curr->next->next;
        }
        if(curr) curr->next = NULL;
        return;
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
    int head[] = {1};
    int len = sizeof(head)/sizeof(head[0]);


    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    obj.reorderList3(root);
    obj.displayList(root);
    return 0;
}

