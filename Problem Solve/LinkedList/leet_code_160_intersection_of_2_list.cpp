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
    int count_node(ListNode* curr, int node_num){
        if(!curr) return node_num;
        return count_node(curr->next, node_num+1);
    }

    ListNode* move_node(ListNode* curr, int move_num){
        if(!curr || move_num==0) return curr;
        return move_node(curr->next, move_num-1);
    }

    ListNode* getNode(ListNode* head1, ListNode* head2){
        if(!head1 || !head2) return NULL;
        // for actual solution it should be
        // head1 == head2   // intersection nodes point same node for both lists

        if(head1->val == head2->val) return head1;
        return getNode(head1->next, head2->next);
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int countA = count_node(headA, 0);
        int countB = count_node(headB, 0);

        int skip_node = countA-countB;

        if(skip_node>0){
            headA = move_node(headA, skip_node);
        }else if (skip_node<0){
            headB = move_node(headB, (-1*skip_node));
        }

        // find intersect node
        return getNode(headA, headB);
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
    ListNode* root1;
    ListNode* root2;
    int list1[] = {4,1,8,4,5};
    int list2[] = {5,6,1,8,4,5};
    int len1 = sizeof(list1)/sizeof(list1[0]);
    int len2 = sizeof(list2)/sizeof(list2[0]);

    (len1>0)? root1= new ListNode(list1[0]):root1 = NULL;
    (len2>0)? root2= new ListNode(list1[0]):root2 = NULL;
//    ListNode* root2 = new ListNode(list2[0]);
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
    ListNode* node = obj.getIntersectionNode(root1, root2);
    obj.displayList(node);
    return 0;
}


/* intersection nodes will be serialized & end of the list
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'


*/
