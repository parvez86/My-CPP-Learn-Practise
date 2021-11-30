#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        //ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
       // ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    bool find_node(ListNode* curr, ListNode* node){
        if(!curr) return false;
        if(curr->val == node->val) return true;
        return find_node(curr->next, node);
    }


public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cNodeList= new ListNode(0);
        ListNode* uNodeList= new ListNode(0);

        // get common of 2 lists
        ListNode* root = cNodeList;
        ListNode* curr = headA;
        while(curr){
            if(find_node(headB, curr)){
                root->next = new ListNode(curr->val);
                root = root->next;
            }
            curr = curr->next;
        }
        // get Intersect Nodes from 1st list
        ListNode* curr1 = headA;
        ListNode* head = uNodeList;

        while(curr1){
            if(!find_node(cNodeList->next, curr1)){
                // cout<< curr1->val<< endl;
                head->next = new ListNode(curr1->val);;
                head = head->next;
            }
            curr1 = curr1->next;
        }

        // get Intersect Nodes from 1st list
        ListNode* curr2 = headB;
        while(curr2){
            if(!find_node(cNodeList->next, curr2)){
                head->next = new ListNode(curr2->val);;
                head = head->next;
            }
            curr2 = curr2->next;
        }
        return uNodeList->next;
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
    int list1[] = {1,2,3,4};
    int list2[] = {1,2,3,4};
    int len1 = sizeof(list1)/sizeof(list1[0]);
    int len2 = sizeof(list2)/sizeof(list2[0]);

    ListNode* root1 = new ListNode(list1[0]);
    ListNode* root2 = new ListNode(list2[0]);
    ListNode* curr = root1;
    for(int i=1; i<len1; i++){
            ListNode* node = new ListNode(list1[i]);
            curr->next = node;
            curr = curr->next;
    }
    curr = root2;
    for(int i=1; i<len2; i++){
            ListNode* node = new ListNode(list2[i]);
            curr->next = node;
            curr = curr->next;
    }
    ListNode* root = obj.getIntersectionNode(root1, root2);
    obj.displayList(root);
    return 0;
}

