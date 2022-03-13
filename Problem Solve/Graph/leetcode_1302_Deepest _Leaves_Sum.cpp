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
    void inOrder(TreeNode* root, int level, int max_level, int&  sum){
        if(!root) return;
        inOrder(root->left, level+1, max_level, sum);
        if(!root->left && !root->right && level == max_level) sum+=root->val;
        inOrder(root->right, level+1, max_level, sum);
    }

    int maxDepth(TreeNode* root){
        if(!root) return 0;
        /*int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1+ max(l, r);*/
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        cout<< "The items are: ";
        //display(root); cout<< endl;
        int sum=0;
        inOrder(root, 1, maxDepth(root), sum);
        return sum;
    }
    void display(TreeNode* root){
        if(!root) return;
        display(root->left);
        cout<< root->val<< " ";
        display(root->right);
    }
};


int main()
{
    Solution obj;
    TreeNode* root = new TreeNode(1);

    // make tree
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(5); root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7); root->right->right->right = new TreeNode(8);

    cout<< obj.deepestLeavesSum(root)<< endl;
    return 0;
}
