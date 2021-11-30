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
     ListNode* find_node(ListNode* curr, int a, bool flag)
    {
        if(!curr) return NULL;
        if(a==0) {
            return (flag)? curr:curr->next;
        }
        return find_node(curr->next, a-1, flag);
    }

    void merge_list(ListNode* curr, ListNode* nodeA, ListNode* nodeB){
        // insert nodeA into the head of the list
        nodeA->val= curr->val;
        nodeA->next = curr->next;

        // iterate until end node founc
        while(curr->next) curr  = curr->next;

        //insert nodeB into the end of the list
        curr->next = nodeB;
        return;
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* nodeA = find_node(list1, a, true);
        ListNode* nodeB = find_node(list1, b, false);

        merge_list(list2, nodeA, nodeB);
        return list1;
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
    int list1[] = {0,1,2,3,4,5};
    int list2[] = {1000000,1000001,1000002};
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
    obj.displayList(root1);
    obj.displayList(root2);

    ListNode* root = obj.mergeInBetween(root1, 3, 5, root2);
    obj.displayList(root);
    return 0;
}

/*
Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]

Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]

[0,3,2,1,4,5]
3
4
[1000000,1000001,1000002]

*/
