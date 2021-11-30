#include <iostream>
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
    ListNode* remove_node(ListNode* curr, int val, int& cnt){
        if(!curr) return NULL;
        if(curr->val == val){
            cnt++;
            if(curr->next) {
                curr->val = curr->next->val;
                curr->next = curr->next->next;
            }else return NULL;
            curr = remove_node(curr, val, cnt);
        }else curr->next=remove_node(curr->next, val, cnt);
        return curr;
    }
    ListNode* remove_nodes(ListNode* head, int val, bool& flag){
        if(!head) return NULL;
        if(head && head->val==val){
            flag = true;
            ListNode* temp = head;
            head = head->next;
           //  while(head && temp->val == head->val) head = head->next;
            head = remove_nodes(head, val, flag);
        }else head->next = remove_nodes(head->next, val, flag);
        return head;
    }

     int remove_node2(ListNode*& curr, int val, int cnt){
        if(!curr) return cnt;
        if(curr->val == val){
            cnt++;
            if(curr->next) {
                curr->val = curr->next->val;
                curr->next = curr->next->next;
            }else curr = NULL;
            return remove_node2(curr, val, cnt);
        }else return remove_node2(curr->next, val, cnt);
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next){
            int cnt=0;
            curr->next = remove_node(curr->next, curr->val, cnt);
            cout<< cnt<< endl;
            if(cnt==0){
                curr = curr->next;
            }else{
                if(curr->next) {
                    curr->val = curr->next->val;
                    curr->next = curr->next->next;
                }
            }
            if(curr)displayList(curr);
        }
        return head;
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
    ListNode* root;
    int head[] = {1, 1, 2, 3, 2, 3, 4, 5, 5};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    root = obj.deleteDuplicates(root);
    obj.displayList(root);

    return 0;
}



/*
Test cases
Input: head = [1,2,3,2,3,4,4,5]
Output: [1,2,5]

Input: head = [1,2,1,3,1]
Output: [2,3]
*/

