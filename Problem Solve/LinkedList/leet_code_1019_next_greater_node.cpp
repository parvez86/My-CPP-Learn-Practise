#include <iostream>
#include <vector>
#include <algorithm>
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
    int get_next_max(ListNode* curr, int val){
        if(!curr) return 0;
        if(curr->val > val) return curr->val;
        return get_next_max(curr->next, val);
    }

    int get_max(vector<int> res, int val){
        int indx = res.size()-1;
        while(indx>0 && res[indx]<=val){
            indx--;
        }
        return (indx>=0 && res[indx]>val)? res[indx]:0;
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode* curr = head;
        while(curr){
            res.push_back(get_next_max(curr->next, curr->val));
            curr = curr->next;
        }
        return res;
    }
    vector<int> nextLargerNodes2(ListNode* head) {
        vector<int> res;
        stack<int> st;
        ListNode* curr = head;
        if(!curr) return res;
        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }
        res.push_back(0);
        int max_prev = st.top();
        st.pop();
        int prev = max_prev;
        while(!st.empty())
        {
            int val = st.top();
            if(val<prev) res.push_back(prev);
            else if(max_prev <= val) res.push_back(0);
            else{
                res.push_back(get_max(res, val));
            }
            if(max_prev < val) max_prev = val;
            prev = val;
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    void displayList(ListNode* head){
        if(head == NULL) {cout<< endl; return;}
        cout<< head->val<< " ";
        displayList(head->next);
    }

    void displayVec(vector<int> arr){
        cout<< "The resultant vector: ";
        for(int i=0; i<arr.size(); i++) cout<< arr[i]<< " ";
        cout<< endl;
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
    obj.displayList(root);
    vector<int> res = obj.nextLargerNodes(root);
    vector<int> res2 = obj.nextLargerNodes2(root);
    obj.displayVec(res);
    obj.displayVec(res2);
    return 0;
}

/* Sample test cases
1.  Input: head = [2,1,5]
    Output: [5,5,0]

2.  Input: head = [2,7,4,3,5]
    Output: [7,0,5,5,0]
*/
