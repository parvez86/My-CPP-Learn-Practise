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
    bool check_palindrome(ListNode* slow_pntr, ListNode* fast_pntr, stack<int>& st){
        // if list is empty return true
        // else return false
        if(!slow_pntr) return st.empty();

        // if slow pointer points second half nodes
        if(!fast_pntr){
            // if list is not empty & list is not palindrome
            // return false
            // else pop a node from stack
            if(!st.empty() && slow_pntr->val != st.top()) return false;
            st.pop();
            return check_palindrome(slow_pntr->next, fast_pntr, st);
        }else if(!fast_pntr->next) return check_palindrome(slow_pntr->next, fast_pntr->next, st);   // for odd length. skip the middle node
        else{   //if slow pointer points first half nodes
            st.push(slow_pntr->val);
            return check_palindrome(slow_pntr->next, fast_pntr->next->next, st);
        }
    }

    bool check_palindrome2(ListNode* head){
        ListNode* pntr = head;
        string str = "";
        while(pntr){
           str += (pntr->val+'0');
            pntr = pntr->next;
        }

        int len = str.size()-1;
        int mid = (int)(0.5*(str.size()+1));
        for(int i=0; i<=mid; i++){
            if(str[i]!=str[len-i]) return false;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        // if list is null
        if(!head) return false;

        // if list contains single node
        if(head && !head->next) return true;
        // for even length list
        if(check_palindrome(head, head, st)) return true;

        // while(!st.empty()) st.pop();

        // for odd length list
        if(check_palindrome(head, head->next, st)) return true;
        return false;
    }
    bool isPalindrome2(ListNode* head) {
        return check_palindrome2(head);
    }
};


int main()
{
    Solution obj;
    ListNode* root;
    int head[] = {1, 2, 3, 2, 1};
    int len = sizeof(head)/sizeof(head[0]);

    (len)? root = new ListNode(head[0]):root = NULL;
    ListNode* curr = root;
    for(int i=1; i<len; i++){
            ListNode* node = new ListNode(head[i]);
            curr->next = node;
            curr = curr->next;
    }
    (obj.isPalindrome(root))?cout<< "Palinrome"<<endl:
        cout<< "Not Palindrome"<< endl;

    (obj.isPalindrome2(root))?cout<< "Palinrome"<<endl:
        cout<< "Not Palindrome"<< endl;

    // obj.displayList(root);
    return 0;
}
