#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* root = new TreeNode;
    TreeNode* addNode(TreeNode* head, int val){
        if(!head){
            head = new TreeNode(val);
        }else{
            if(head->val >= val) head->left = addNode(head->left, val);
            else head->right = addNode(head->right, val);
        }

        return head;
    }

    void inorder(TreeNode* curr){
        if(!curr) return;
        inorder(curr->left);
        root = addNode(root, curr->val);
        inorder(curr->right);
    }

    void getPreOrder(TreeNode* root, TreeNode*& root1){

        if(!root) return;
        getPreOrder(root->left, root1);
        root1 = addNode(root1, root->val);
        getPreOrder(root->right, root1);
    }

    void display_in_pre_order(TreeNode* root){
        if(!root) {cout<< endl; return;}
        display_in_pre_order(root->left);
        cout<< root->val<< " ";
        display_in_pre_order(root->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* new_root = NULL;
        TreeNode* curr = root;
        getPreOrder(root, new_root);

        return new_root;
    }
    TreeNode* makeTree(TreeNode* head, int val){
        return addNode(head, val);
    }
    void displayTree(TreeNode* head){
        cout<< "The elements of tree: ";
        display_in_pre_order(head);
    }
};


int main()
{
    Solution obj;
    TreeNode* root1;
    TreeNode* root2;
    int head1[] = {5,3,6,2,4,NULL,8,1,NULL,NULL,NULL,7,9};
    int len1 = sizeof(head1)/sizeof(head1[0]);
    if(len1>0){
        root1 = new TreeNode(head1[0]);
        for(int i=1; i<len1; i++){
            if(head1[i]) root1 = obj.makeTree(root1, head1[i]);
        }
    }

    TreeNode* root= obj.increasingBST(root1);
    obj.displayTree(root);
    return 0;
}



/*
Test cases
Input: root = [5,1,7]
Output: [1,null,5,null,7]

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
*/


