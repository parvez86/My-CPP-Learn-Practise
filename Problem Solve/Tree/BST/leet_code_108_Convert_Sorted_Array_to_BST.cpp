#include <iostream>
#include <vector>
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

    TreeNode* getBalancedBST(vector<int>& vec, int l, int r){
        if(l>r) return NULL;
        int mid = l+(r-l)*0.5;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = getBalancedBST(vec, l, mid-1);
        root->right = getBalancedBST(vec, mid+1, r);

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getBalancedBST(nums, 0, nums.size()-1);
    }

    void display(TreeNode* root){
        cout<< "The nodes are (pre-order): ";
        preOrder(root);
        cout<< endl;
    }

    void displayIn(TreeNode* root){
        cout<< "The nodes are (in-order): ";
        inOrder(root);
        cout<< endl;
    }
};

int main()
{
    Solution obj;
    vector<int> nums{-10,-3, 0, 5,9};
    TreeNode* root = obj.sortedArrayToBST(nums);
    obj.display(root);
    obj.displayIn(root);
    return 0;
}

