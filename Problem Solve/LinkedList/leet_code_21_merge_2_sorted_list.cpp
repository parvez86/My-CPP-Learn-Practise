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

public:

    void merge_list(ListNode* l1, ListNode* l2, ListNode*& res_list){
        if(!l1 && !l2) return;

        if(!l2 || (l1 && l1->val < l2->val)){
            res_list = l1;
            l1 = l1->next;
        }else {
            res_list = l2;
            l2 = l2->next;
        }
        merge_list(l1, l2, res_list->next);
    }

    void merge_list2(ListNode* l1, ListNode* l2, ListNode*& result_list){
        while(l1 || l2){
            if(!l2 || (l1&& l1->val < l2->val)){
                result_list->next = l1;
                result_list = result_list->next;
                l1 = l1->next;
            }else{
                result_list->next = l2;
                result_list = result_list->next;
                l2 = l2->next;
            }
        }
        return;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // merge 2 list using recursion
        ListNode* result_list = new ListNode(0);
        ListNode* res_head = result_list;
        merge_list(l1, l2, result_list->next);
        displayList(res_head->next);

        /*
       // merge 2 list using iterative approach
        ListNode* result_list2 = new ListNode(0);
        ListNode* res_head = result_list2;
        merge_list2(l1, l2, result_list2);
        displayList(res_head->next);
        */
        return res_head->next;
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
    obj.displayList(root1);
    obj.displayList(root2);

    ListNode* root = obj.mergeTwoLists(root1, root2);
    // obj.displayList(root);
    return 0;
}

/*

l1 = [1,2,4], l2 = [1,3,4]
l1 = [], l2 = []

*/
