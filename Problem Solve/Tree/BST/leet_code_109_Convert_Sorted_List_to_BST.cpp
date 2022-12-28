
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    ListNode* getMid(ListNode* slow_pntr, ListNode* fast_pntr, ListNode* end_node){
        if(!fast_pntr || fast_pntr->next == end_node || fast_pntr->next->next == end_node) return slow_pntr;
        return getMid(slow_pntr->next, fast_pntr->next->next, end_node);
    }

    TreeNode* getBalancedBST(ListNode* start_node, ListNode* end_node){
        if(start_node == end_node) return NULL;
        if(start_node->next == end_node) return new TreeNode(start_node->val);

        ListNode* mid_node = getMid(start_node, start_node, end_node);
        TreeNode* root = new TreeNode(mid_node->val);

        root->left = getBalancedBST(start_node, mid_node);
        root->right = getBalancedBST(mid_node->next, end_node);

        return root;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout<< root->val<< " ";
        inOrder(root->right);
    }

    void preOrder(TreeNode* root){
        if(!root) return;
        cout<< root->val<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return getBalancedBST(head, NULL);
    }

    void display(TreeNode* root){
        cout<< "The nodes are: ";
        preOrder(root);
        cout<< endl;
    }

    void displayIn(TreeNode* root){
        cout<< "The nodes are (in-order): ";
        inOrder(root);
        cout<< endl;
    }

    void display_list(ListNode* head){
        cout<< "The items of list: ";
        while(head){
            cout<< head->val<< " ";
            head = head->next;
        }
        cout<< endl;
    }
};

int main()
{
    Solution obj;
    vector<int> nums{-10,-3, 0, 5,9};
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    int len = nums.size();
    for(int i=1; i<len; i++) {
        // if(nums[i] == NULL) continue;
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    obj.display_list(head);
    TreeNode* root = obj.sortedListToBST(head);
    obj.displayIn(root);
    return 0;
}
