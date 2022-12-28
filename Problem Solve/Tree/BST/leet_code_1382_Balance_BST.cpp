#include <bits/stdc++.h>

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
    TreeNode* b_root = NULL;

    int getHeight(TreeNode* root){
        if(!root) return -1;
        int l_height = getHeight(root->left)+1;
        int r_height = getHeight(root->right)+1;
        return (l_height > r_height)? l_height:r_height;
    }

    // ll
    TreeNode* ll_rotation(TreeNode* root){
        TreeNode* new_root = root->left;

        root->left = new_root->right;
        new_root->right = root;

        return new_root;
    }

    TreeNode* rr_rotation(TreeNode* root){
        TreeNode* new_root = root->right;

        root->right = new_root->left;
        new_root->left = root;

        return new_root;
    }


    TreeNode* addItem(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(val < root->val) root->left = addItem(root->left, val);
        else if(val > root->val) root->right = addItem(root->right, val);
        else return root;

        // get height
        int l_height = (!root->left)? 0:getHeight(root->left);
        int r_height = (!root->right)? 0:getHeight(root->right);

        int balance = l_height - r_height;
        if(balance < -1 && val != root->right->val){
            if(val < root->right->val) root->right = ll_rotation(root->right); // for rl rotation
            return rr_rotation(root);
        }else if (balance > 1 && val != root->left->val){
            if(val > root->left->val) root->left = rr_rotation(root->left); // for lr rotation
            return ll_rotation(root);
        }

        return root;
    }

    void inOrderAdd(TreeNode* curr){
        if(!curr) return;
        inOrderAdd(curr->left);
        b_root = addItem(b_root, curr->val);
        inOrderAdd(curr->right);
    }


    void preOrder(TreeNode* root){
        if(!root) return;
        cout<< root->val<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout<< root->val<< " ";
        inOrder(root->right);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrderAdd(root);
        return b_root;
    }
    TreeNode* balanceBST2(vector<int> vec) {
        TreeNode* new_root = NULL;
        int len = vec.size();
        for(int i=0; i<len; i++){
            if(!vec[i]) continue;
            b_root = addItem(b_root, vec[i]);
        }
        return b_root;
    }
    void display(TreeNode* root){
        cout<< "The nodes are: ";
        preOrder(root);
        cout<< endl;
    }
    void displayIn(TreeNode* root){
        cout<< "The nodes are: ";
        inOrder(root);
        cout<< endl;
    }
};

int main()
{
    Solution obj;
    vector<int> vec{1,NULL,2,NULL,3,NULL,4,NULL,NULL};
    TreeNode* root = obj.balanceBST2(vec);
    obj.display(root);
    obj.displayIn(root);
    return 0;
}
