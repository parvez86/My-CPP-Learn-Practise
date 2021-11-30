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
    // using recursion
    void getInt(ListNode* curr, int& num){
        if(!curr) return;
        num <<= 1;  // multiply result with 2
        num |= curr->val;   // add the node value with result
        getInt(curr->next, num);
    }

    int getInt2(ListNode* head){
        ListNode* curr = head;
        int result = 0;
        while(curr){
            result = (result << 1) | (curr->val);
            curr = curr->next;

        }
        return result;
    }

    int getDecimalValue(ListNode* head) {

        // for method 1
        // recursive approach
        // int result = 0;
        // getInt(head, result);

        // for method 2
        // iterative approach
        int result = getInt2(head);
        return result;
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
    int head[] = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    int len = sizeof(head)/sizeof(head[0]);

    ListNode* root = new ListNode(head[0]);
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    cout<< obj.getDecimalValue((root))<< endl;
    return 0;
}


/* sample test cases
head = [0]
head = [1]
head = [0,0]
head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]

*/
