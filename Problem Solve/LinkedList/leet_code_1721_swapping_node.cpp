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


    ListNode* find_prev(ListNode* head, int p){
        if(!head || p==0) return NULL;

        if(p==1) return head;

        return find_prev(head->next, p-1);
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {

        // for 1-based index
        int cnt = count_nodes(head, 0)+1;
        //
        int m,n;

        // if the number of node is odd & k indicates mid-point of the list
        // return unchanged
        if(cnt%2==0 && cnt/2==k) return head;

        // find the index of the 2 nodes
        if(k+k<cnt){
            m=k;n=cnt-k;
        }else {
            m=cnt-k;n=k;
        }

        // get the previous of the 2 nodes
        ListNode* prev1 = find_prev(head, m-1);
        ListNode* prev2 = find_prev(head, n-1);

        // get the 2 nodes
        ListNode* node1 = (prev1)?prev1->next:head;
        ListNode* node2 = (prev2)?prev2->next:NULL;

        // swap the 2 nodes
        // store the next of 2nd swap node
        ListNode* temp = node2->next;

        // if the previous of 1st swap node is NULL
        // it points the head of the list, assign the 2nd swap node as head
        // else, points the 2nd swap node next to the previous node of the 1st swap node
        (prev1)? prev1->next = node2: head = node2;

        // if the 2nd swap node is not next to the 1st node
        // points the next of the 1st swap node to the next of the 2nd swap node
        // else, points the 1st swap node to the next of the 2nd swap node
        node2->next = (node1->next != node2)? node1->next: node1;

        // if the 1st swap node is not to the next of 2nd swap node (prev2 != node1)
        // then, points the 1st swap node as the next of the previous of 2nd swap node
        // points the temp to the next of 1st swap node
        if(node2->next != node1) prev2->next = node1;
        node1->next = temp;

        return head;
    }

    ListNode* swapNodes2(ListNode* head, int k) {
        // find total numbers of node
        // 1 is added for 1-based index
        int cnt = count_nodes(head, 0)+1;

        // get 1st swap node
        ListNode* node1 = find_prev(head, k);
        // get 2nd swap node
        ListNode* node2 = find_prev(head, cnt-k);

        // if the 2 nodes are same, return
        if(node1->val==node2->val) return head;

        // swap value
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
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
    ListNode* root;
    int head[] = {7,9,6,6,7,8,3,0,9};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.swapNodes2(root, 4);
    obj.displayList(root);
    return 0;
}

/*
ListNode* temp = (node2->next)?node2->next:NULL;
        if(temp) cout<< temp->val<< endl;
        node2->next = (!node1)? head->next:(node1->next != node2)?node1->next:node1;
        if(node2->next) cout<< node2->next->val<< endl;
        node1->next = temp;
        if(node1->next) cout<< node1->next->val<< endl;
        //assign the 2 node
        (prev1)? prev1->next = node2:head=node2;
        if(prev2 != node1) prev2->next = node1;
*/
